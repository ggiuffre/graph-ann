TEMPLATE = app
TARGET = GUI
INCLUDEPATH += .
INCLUDEPATH += $$PWD/logica/
QT += widgets
CONFIG += c++11

# Input
HEADERS += corn_window.h net_interface.h nets_list.h net_builder_widget.h net_trainer_widget.h net_runner_widget.h data_builder_widget.h \
			logica/dag.h logica/network.h logica/net_container.h logica/internetwork.h logica/layered_net.h logica/layered_biased_net.h logica/nets.h
SOURCES += gui_main.cpp corn_window.cpp net_interface.cpp nets_list.cpp net_builder_widget.cpp net_trainer_widget.cpp net_runner_widget.cpp data_builder_widget.cpp \
			logica/dag.cpp logica/network.cpp logica/net_container.cpp logica/internetwork.cpp logica/layered_net.cpp logica/layered_biased_net.cpp logica/train.cpp logica/nets.cpp
