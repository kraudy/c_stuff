#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main() {
	// Disable output buffering
	setbuf(stdout, NULL);
 	setbuf(stderr, NULL);

	// You can use print statements as follows for debugging, they'll be visible when running tests.
	printf("Logs from your program will appear here!\n");

	int server_fd, client_addr_len;
	struct sockaddr_in client_addr;
  // Lo que le dicen server es basicamente un socket a la escucha
	// Crea el socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
  	printf("Socket creation failed: %s...\n", strerror(errno));
  	return 1;
  }
	
  // Since the tester restarts your program quite often, setting SO_REUSEADDR
  // ensures that we don't run into 'Address already in use' errors
  int reuse = 1;
  // Agrega configuracion al socket
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
  	printf("SO_REUSEADDR failed: %s \n", strerror(errno));
  	return 1;
  }
  // Here we are initialiazing the struct
	// Describe socket a IPv4, puerto 4221, ordenamiento de bytes de red, htons e interfaces de red
  struct sockaddr_in serv_addr = { .sin_family = AF_INET ,
  								 .sin_port = htons(4221),
  								 .sin_addr = { htonl(INADDR_ANY) },
  								};
	// Amarra el socket
  if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) != 0) {
  	printf("Bind failed: %s \n", strerror(errno));
  	return 1;
  }
	// Escucha por conexiones
  int connection_backlog = 5;
  // server_fd es un socket pasivo, diferente del client_fd
  if (listen(server_fd, connection_backlog) != 0) {
  	printf("Listen failed: %s \n", strerror(errno));
  	return 1;
  }
	//
  printf("Waiting for a client to connect...\n");
  client_addr_len = sizeof(client_addr);
	// Cuando el ciente se conecta se  al socket genera otro file descriptor
  int client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_fd < 0)
  {
    printf("Error. El client no pudo conectarse");
  }
  
  printf("Client connected\n");

  printf("Leyendo request \n");

  // Lee el request del client
  char buffer[1024];
  ssize_t bytes_recibidos = read(client_fd, buffer, sizeof(buffer));
  if (bytes_recibidos <= 0)
  {
    printf("Error al leer request");
    return(1);
  }
  
  printf("Request recibido: %.*s\n", (int)bytes_recibidos, buffer);

  // Pareseo del request
  char* verbo = strtok(buffer, " "); 
  char* url   = strtok(NULL, " ");

  if (!(verbo && url))
  {
    printf("No se pudo obtener el verbo y la url");
    return(1);
  }

  printf("Url a parsear: %s\n", url);

  char* reply;
  if (strcmp(url, "/") == 0)
  {
    reply = "HTTP/1.1 200 OK\r\n\r\n";
  }else{

    reply = "HTTP/1.1 400 Not Found\r\n\r\n";
  } 

  // Envia la respuesta al client
  int bytes_send = send(client_fd, reply, strlen(reply), 0);
  printf("Bytes enviados: %i \n", bytes_send);
  if (bytes_send <= 0)
  {
    printf("Error al enviar respuesta");
    return(1);
  }
  
  printf("Respuesta enviada: %s", reply);

  // Cierra conexion del cliente
  close(client_fd);

	// Cierra el socket de escucha
  close(server_fd);

	return 0;
}
