hello: hello_world.c
	mpicc -Wall -o hello_world hello_world.c

my_mpi: my_mpi.c
	mpicc -Wall -fpic -shared -o my_mpi.so my_mpi.c

ping_pong: ping_pong.c
	mpicc -Wall -o ping_pong ping_pong.c

runhello:
	LD_PRELOAD=./my_mpi.so ./hello_world

runping_pong: 
	LD_PRELOAD=./my_mpi.so ./ping_pong

clean:
	rm *~

