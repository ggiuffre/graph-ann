rete_totale: gprova train layered_net network dag graph
	g++ gprova.o train.o layered_net.o network.o dag.o graph.o

gprova: gprova.cpp layered_net.h nets.h
	g++ -c gprova.cpp -o gprova.o

train: train.cpp layered_net.h
	g++ -c train.cpp -o train.o

nets: nets.cpp nets.h
	g++ -c nets.cpp -o nets.o

layered_net: layered_net.cpp layered_net.h
	g++ -c layered_net.cpp -o layered_net.o

network: network.cpp network.h
	g++ -c network.cpp -o network.o

dag: dag.cpp dag.h
	g++ -c dag.cpp -o dag.o

graph: graph.cpp graph.h
	g++ -c graph.cpp -o graph.o

clean:
	rm *.o