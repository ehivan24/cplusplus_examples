/* 
 * File:   main.cpp
 * Author: edwingsantos
 *
 * Created on December 15, 2014, 7:27 PM
 */

#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <exception>
#include <pthread.h>

using namespace std;

 void foo(void){
     int max =100;
  for(int i=0; i < max; i++){
      cout << "\t" << i *2 << endl;
  }   
 }
 
 void bar (void){
     int max = 100;
     for(int i=0; i < max; i++){
      cout << i *2 << endl;
    }   
 }
 
 void alice (void){
     int x = 5;
     while(x < 90){
         x +=5;
         cout << x << endl;
     }
 }
 
 int * pointerToStatic(){
     
     static int i = 190;
     return &i;
 }
 
 
int main(int argc, char** argv) {
  
    thread f(foo); 
    thread b(bar);
    thread a(alice);
    
    
    try{
        f.join();
        f.detach();
        sleep(2);
        b.join();
        b.detach();
        sleep(2);
        a.join();
        a.detach();
        sleep(2);
    }catch(exception &e){
        cout << e.what() << endl;
    }
    //b.swap(f);
    //f.swap(b);
   
    cout << pointerToStatic() << endl;
    
    sleep(3);
    int max = 20;
	char *buffer;
	buffer = (char*)malloc( (max+1)* sizeof(char));
	if(buffer != NULL) {
		for(int i = 0; i < max; i++){ 
			buffer[i] = 'a'+ i;     
                }        
		buffer[max] = '\0';

                  // This will print out "buffer=abcdefghij"
		printf("buffer=%s\n",buffer);   

		free (buffer);
		return 0;
	}
	else {
		printf("Not enough memory\n");
		return 1;
	}
    

    return 0;
}

