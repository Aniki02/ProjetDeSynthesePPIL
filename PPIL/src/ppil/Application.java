package ppil;

import java.net.ServerSocket;
import java.net.Socket;
/**
 * <b>Application</b>
 *<i>le programme principal main</i>
 *@see Application#main(String[])
 */
public class Application {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/**
		 * <i>le port de communication.</i>
		 * */
		int port = 8091;
		try 
		{
			 ServerSocket serveurDessin = new ServerSocket(port);/**le serveur à l'écoute.*/
			 System.out.println("serveur de dessin prêt, \n détails : "+serveurDessin);
			 int nombreClients;/**<i>le compteur des clients connectés</i>*/
			 nombreClients = 0;
			 
			 while(true)
			 {
				 /**<p>Boucle sur les clients</p>*/
				System.out.println("serveur de dessin en attente du prochain client");
				Socket socket = serveurDessin.accept();/**<p>reste bloquante tant qu'elle n'a pas détecté de connexion et accepte un client.</p>*/
				++nombreClients;
				System.out.println("nouveau client connecté n° = " + nombreClients);
				Accepter_client client = new Accepter_client(socket);/**transmet les informations du client connecté à Accepter_client*/
				client.start();/**appel la methode run de Accepter_client qui extends de Thread*/
			 }
		}
		catch (Exception e) {
			/**
			 * <p>lève une exception si une erreur survient au moment de la connexion.</p>
			 */
			// TODO: handle exception
			System.err.println("Le serveur n'a pu être connecté sur le port d'écoute ou la connexion sur ce port a été rompue. \n Détails : "+e);
		}

	}

}
