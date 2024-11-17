char const HTTP_200_OK[] = "..."


//    /add?Value=N 
//    add N to number and shows the output



if(strcmp(path, "/add") == 0){ 
//만약 path 가 /add?Value=44 이런거라면 strcmp안에 /add 와 동일하지않다.

    ...

}

그러기 위해서는 strncmp를 쓴다 
4개 까지 비교하게 해주는 펑션이다.
이렇게하면 /add?Value=44 이런거라면 strcmp안에 /add 와 4자리까지는 /add로 동일하다
if(strncmp(path,"/add", 4)){

handle_add(client_socket, path)
}

char addprefix[] = "/add?value="
void handle_add(int client_socket, char* path){
    // Assume: path looks like "/add?value=__________"
    // atoi -> convert string "123" to integer 123

    char* start_of_num = strstr(path, "=") + 1; // IDEA 2\
    int toadd = atoi(start_of_num);
    num += toadd;
    char message[BUFFER_SIZE];
    snprintf(message, BUFFER_SIZE, "Added %d, got: %d\n", toadd, num);
    write(client_socket, HTTP_200_OK, strlen(HTTP_200_OK)); // HTTP_200_OK 를 지정해놨다고 1 line에서
    write(client_socket, message, strlen(message));

}