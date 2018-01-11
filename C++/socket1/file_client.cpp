#include<netinet/in.h>                    
#include<sys/types.h>              
#include<sys/socket.h>                  
#include<stdio.h>                         
#include<stdlib.h>                       
#include<string.h> 
#include<unistd.h>                        
#include<iostream>
#include<arpa/inet.h>
#define SERVER_PORT 6666  
#define BUFFER_SIZE 1024  
#define FILE_NAME_MAX_SIZE 512  
using namespace std;
  
int main(int argc, char **argv)  
{  
    if (argc != 2){  
        cout<<"Usage: ./"<<argv[0]<<"ServerIPAddress"<<endl;  
        exit(1);  
    }   
    struct sockaddr_in client_addr;  
    bzero(&client_addr, sizeof(client_addr));  
    client_addr.sin_family = AF_INET; 
    client_addr.sin_addr.s_addr = htons(INADDR_ANY);
    client_addr.sin_port = htons(0); 
  
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);  
    if (client_socket < 0){  
        cout<<"Create Socket Failed!"<<endl;  
        exit(1);  
    }   
    if (bind(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr))){  
        cout<<"Client Bind Port Failed!"<<endl;  
        exit(1);  
    }  
    struct sockaddr_in  server_addr;  
    bzero(&server_addr, sizeof(server_addr));  
    server_addr.sin_family = AF_INET;   
    if (inet_aton(argv[1], &server_addr.sin_addr) == 0) {  
        cout<<"Server IP Address Error!"<<endl;  
        exit(1);  
    }  
  
    server_addr.sin_port = htons(SERVER_PORT);  
    socklen_t server_addr_length = sizeof(server_addr);   
    if (connect(client_socket, (struct sockaddr*)&server_addr, server_addr_length) < 0){  
        cout<<"Can Not Connect To"<<argv[1]<<"!"<<endl;  
        exit(1);  
    }  
  
    char file_name[FILE_NAME_MAX_SIZE + 1];  
    bzero(file_name, sizeof(file_name));
    cout<<"The Server File List:"<<endl;
    cout<<"1.txt\t2.txt\t3.txt\t4.txt\t5.txt\t6.txt\t7.txt\t8.txt\t9.txt\t10.txt"<<endl;  
    cout<<"Please Input File Name On Server."<<endl;  
    cin>>file_name;  
  
    char buffer[BUFFER_SIZE];  
    bzero(buffer, sizeof(buffer));  
    strncpy(buffer, file_name, strlen(file_name) > BUFFER_SIZE ? BUFFER_SIZE : strlen(file_name));  
    send(client_socket, buffer, BUFFER_SIZE, 0);  
  
    FILE *fp = fopen(file_name, "w");  
    if (fp == NULL){  
        printf("File:\t%s Can Not Open To Write!\n", file_name);  
        exit(1);  
    }  
  
    bzero(buffer, sizeof(buffer));  
    int length = 0;  
    while((length = recv(client_socket, buffer, BUFFER_SIZE, 0))){  
        if (length < 0){  
            printf("Recieve Data From Server %s Failed!\n", argv[1]);  
            break;  
        }  
  
        int write_length = fwrite(buffer, sizeof(char), length, fp);  
        if (write_length < length){  
            printf("File:\t%s Write Failed!\n", file_name);  
            break;  
        }  
        bzero(buffer, BUFFER_SIZE);  
    }  
  
    printf("Recieve File:\t %s From Server[%s] Finished!\n", file_name, argv[1]);   
    fclose(fp);  
    close(client_socket);  
    return 0;  
}  
