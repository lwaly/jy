g++ -o client main.cpp pushdata.cpp CBuffer.cpp msg.pb.cc -L../../thirdlib/lib -lev -lprotobuf -I../../thirdlib/include -lpthread
export LD_LIBRARY_PATH=/home/ly/jy/code/thirdlib/lib
./client 192.168.0.20 16001