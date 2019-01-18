#include <iostream>
#include <sstream>
#include <regex>
#include "ClientDessin.hpp"

ClientDessin * ClientDessin::dessin = new ClientDessin("127.0.0.1", 8091);
ClientDessin::ClientDessin(const std::string adresse, const int port){
    /** @INITIALISATION_CREATION
     * _initialisation  et création du sock 
    */
   creat_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
   if(creat_socket == -1) std::cerr<<"L'initialisation et la creation  a echoue";
    std::cout<<"socket de dessin cree!"<<std::endl;
    /**
     * @CREATION_REPRESENTANT_LOCAL_SERVER_DISTANT
     * _grace à sockaddr_in
    */
   param_connexion.sin_family = AF_INET;
   param_connexion.sin_port = htons((short)8091);
   inet_pton(param_connexion.sin_family, adresse.c_str(), &param_connexion.sin_addr);

    int connexion;
    connexion = connect(creat_socket, (sockaddr *) &param_connexion, sizeof(param_connexion));
    if(connexion!=0){
        std::cerr<<"La connexion à echoue";
    }
}
ClientDessin::~ClientDessin(){
    int fermeture = close(creat_socket);
    if(fermeture !=0)
        std::cerr<<"Echec de la fermeture du socket!";
}
void ClientDessin::ouvertureFenetre(const std::string titre, const int x, const int y, const int width,  const int height)const{
    std::ostringstream oss;
    oss <<titre<< "," << x << "," << y << ","<<
	width<<","<<height;
    //std::string requet = oss.str();

    envoiRequete(oss.str()); //_envoi la requête qui ouvre la fenêtre avec les informations renseignez
}
void ClientDessin::dessineSegment(const std::string type, const Couleur color, 
                                const Vecteur2D origine, 
                                const Vecteur2D arrive)const
{
    std::ostringstream oss;
    oss<<type<<","<<couleurEnchaine(color)
    <<","<<vecteurEnchaine(origine)
    <<","<<vecteurEnchaine(arrive);


    std::cout<< "requete envoyer :"<<oss.str();
    envoiRequete(oss.str());
}

void ClientDessin::dessineCercle(const std::string type, const Couleur color, 
                    const Vecteur2D centre, const double rayon)const
{
    std::ostringstream oss;
    oss<<type<<","<<couleurEnchaine(color)
    <<","<<vecteurEnchaine(centre)
    <<","<<rayon;

    std::cout<< "requete envoyer :"<<oss.str();
    envoiRequete(oss.str());
}

void ClientDessin::dessinePolygone(const std::string type, const Couleur color, 
                                    const vector <Vecteur2D> points)const
{
    int nbPoints = points.size();

    std::ostringstream oss;
    oss<<type<<","<<nbPoints<<","<<couleurEnchaine(color)
    <<tabVectorEnchaine(points)<<endl;

    std::cout<< "requete envoyer :"<<oss.str();
    envoiRequete(oss.str());
}
const ClientDessin * ClientDessin::getClient(){
    if(!dessin) dessin = new ClientDessin("127.0.0.1", 8091);
    return dessin;
}
/*
    Transforme un objet vecteur en string separé par des virgules
*/
std::string ClientDessin::vecteurEnchaine(const Vecteur2D v)const{
    std::ostringstream oss;
    oss<<v._x<<","<<v._y;

    string s =  oss.str();
    return s;
}
/*
    Transforme un objet couleur en string separé par des virgules
*/
std::string ClientDessin::couleurEnchaine(const Couleur c) const{
    std::ostringstream oss;
    oss<<c.getCouleur1()<<","
        <<c.getCouleur2()<<","
        <<c.getCouleur3();

    string s =  oss.str();
    return s;
}
std::string ClientDessin::tabVectorEnchaine(const vector<Vecteur2D> points) const{
    std::ostringstream oss;
    vector <Vecteur2D>::const_iterator it;
    for(it=points.begin(); it!=points.end(); it++)
        oss<<","<<it->_x<<","<<it->_y;

    std::string chaineCordonnees = oss.str();
    return chaineCordonnees;
}
/*
    Envoi une requête au serveur
*/
void ClientDessin::envoiRequete(std::string requete)const{
    int envoi;
    char t[LONGUEURMAXMESSAGE];
    strcpy(t, requete.c_str());
    strcat(t, "\n");
    int l = strlen(t);
    envoi = send(creat_socket,t, strlen(t),0);
    if(envoi != l) throw "Echec d'ouverture de la fenêtre!";
}