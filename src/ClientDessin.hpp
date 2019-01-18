#ifndef __CLIENTDESSIN__
#define __CLIENTDESSIN__
    #include <ostream>
    #include <string>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <netdb.h>
    #include <string.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include "Vecteur2D.hpp"
    #include "Couleur.hpp"
    #include <vector>
    #define LONGUEURMAXMESSAGE 500

    class ClientDessin
    {
        private:
            int creat_socket;
            sockaddr_in param_connexion;
            ClientDessin(const std::string adresse, const int port);
            static ClientDessin * dessin;
        public:
            const static ClientDessin * getClient();
            void ouvertureFenetre(const std::string titre, const int x, const int y, int width, int height)const;
            void dessineSegment(const std::string type, const Couleur color, 
                                const Vecteur2D origine, 
                                const Vecteur2D arrive)const;
            void dessineCercle(const std::string type, const Couleur color, const Vecteur2D centre, const double rayon)const;
            void dessinePolygone(const std::string type, const Couleur color, const vector <Vecteur2D> points)const;

        private:
            std::string vecteurEnchaine(const Vecteur2D v)const;
            std::string couleurEnchaine(const Couleur c) const;
            std::string tabVectorEnchaine(const vector<Vecteur2D> points) const;
            void envoiRequete(std::string requete)const;

            ~ClientDessin();
    };
#endif