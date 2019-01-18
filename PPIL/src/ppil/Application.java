package ppil;

import java.net.ServerSocket;
import java.net.Socket;

public class Application {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int port = 8091;
		try 
		{
			 ServerSocket serveurDessin = new ServerSocket(port);
			 System.out.println("serveur de dessin prêt, \n détails : "+serveurDessin);
			 int nombreClients;
			 nombreClients = 0;
			 
			 while(true)
			 {
				System.out.println("serveur de dessin en attente du prochain client");
				Socket socket = serveurDessin.accept();
				++nombreClients;
				System.out.println("nouveau client connecté n° = " + nombreClients);
				Accepter_client client = new Accepter_client(socket);
				client.start();
			 }
		}
		catch (Exception e) {
			// TODO: handle exception
			System.err.println("Le serveur n'a pu être connecté sur le port d'écoute ou la connexion sur ce port a été rompue. \n Détails : "+e);
		}

	}

}
