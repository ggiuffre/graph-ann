CC = clang++
FLAGS = -Wall -std=c++11
GDB = -g

build: dag.o network.o net_container.o internetwork.o layered_net.o layered_biased_net.o nets.o train.o
	$(CC) $(FLAGS) gprova.cpp dag.o network.o net_container.o internetwork.o layered_net.o layered_biased_net.o nets.o train.o

dag.o: dag.cpp dag.h
	$(CC) -c -o dag.o dag.cpp $(FLAGS)

network.o: network.cpp network.h dag.h
	$(CC) -c -o network.o network.cpp $(FLAGS)

net_container.o: net_container.cpp net_container.h network.h dag.h
	$(CC) -c -o net_container.o net_container.cpp $(FLAGS)

internetwork.o: internetwork.cpp internetwork.h network.h net_container.h dag.h
	$(CC) -c -o internetwork.o internetwork.cpp $(FLAGS)

layered_net.o: layered_net.cpp layered_net.h network.h dag.h
	$(CC) -c -o layered_net.o layered_net.cpp $(FLAGS)

layered_biased_net.o: layered_biased_net.cpp layered_biased_net.h layered_net.h network.h dag.h
	$(CC) -c -o layered_biased_net.o layered_biased_net.cpp $(FLAGS)

nets.o: nets.cpp nets.h layered_biased_net.h layered_net.h network.h dag.h
	$(CC) -c -o nets.o nets.cpp $(FLAGS)

train.o: train.cpp nets.h layered_biased_net.h layered_net.h network.h dag.h
	$(CC) -c -o train.o train.cpp $(FLAGS)

clean:
	rm -f -R *.o a.out a.out.dSYM

rebuild: clean build

debug: dag.o network.o net_container.o internetwork.o layered_net.o layered_biased_net.o nets.o train.o
	$(CC) $(GDB) $(FLAGS) gprova.cpp dag.o network.o net_container.o internetwork.o layered_net.o layered_biased_net.o nets.o train.o
