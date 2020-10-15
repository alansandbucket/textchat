class Server
{
    public:
    Server();
    void createSocket();
    void handleConnections();

    private:
    int listenSocket;
    int addUser();
}