#include <stdio.h>
#include "scclient.c"

// include the cross-platform thread sleep function
#include "sleep.c"

void _callback(char * event,json_object *error,json_object *data){
    printf("Callback got called ,I'm finally done");
}

void _connect(struct socket * s)
{
    printf("successfully connected");
    // int a;
    // scanf("%d",&a);
    // s->emitstring((char *)"sampleClientEvent",(char *)"Hey there buddy !!!");
    //s->emitintack((char *)"chat",1,&_callback);

	// set a delay before sending the command to prevent collision on the server side
	sleep_ms (100);

	s->emitstring ((char *)"sampleClientEvent", (char *)"Hey there buddy !!!");
}


void on_chat(struct ackdata *ack,json_object *data,callback f){
    printf("got event for %s and data is %s",ack->name,json_object_to_json_string(data));
    f(ack,json_object_new_string("sample error"),json_object_new_string("sample data"));
}

void disconnect(struct socket * s)
{
    printf("successfully dis-connected");
}

void connect_error(struct socket * s)
{
    printf("successful connect error");
}
void on_auth(struct socket * s,bool isauthenticated)
{
    printf("Authentication is %s",isauthenticated ? "true" : "false");
}
void on_set_auth_token(struct socket * s,char * token)
{
    printf("on token got called");
}

int main()
{
     
    s= Socket ((char *)"ws",(char *)"localhost",8000,(char *)"/socketcluster/",NULL,-1);
    s->connect_callback=&_connect;
    s->disconnect_callback=&disconnect;
    s->connect_error_callback=&connect_error;    
    s->onauth_callback=&on_auth;
    s->onauthtoken_callback=&on_set_auth_token;
    s->onack((char *)"chat",&on_chat);
    s->connect();


    s->disconnect();

	
}