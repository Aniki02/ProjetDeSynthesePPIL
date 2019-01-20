package ppil;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.SocketException;
/**
 * <b>Accepter_client elle extends Thread </b>
 *<p>Afin d'accepter plusieurs clients à la fois on n'est obliger de extendre Thread (c'est tà dire faire une file) ou implements Runnable ...
 *</p>
 
 *@see Accepter_client#run()
 *@see Accepter_client#socket
 *@see Accepter_client#tab_cordonne
 *@see Accepter_client#titre
 *@see Accepter_client#fluxEntrant
 *@see Accepter_client#informationDeLaFenetre(String)
 */
public class Accepter_client extends Thread {
	/**
	 * socket la prise (port) mise en place.
	 * */
	private Socket socket;
	/**
	 * lecture sur le tempon (buffere)
	 */
	private BufferedReader fluxEntrant;
	
	private String titre; /** la première lecture sera les infos de la fenetre donc le titre*/
	private int tab_cordonne[]=new int[4];/**Les coordonnés*/
	
	public Accepter_client(Socket socket) throws IOException{
		this.socket = socket;
		this.fluxEntrant= new BufferedReader(new InputStreamReader(socket.getInputStream()));/**on instance le flux de lecture sur le tempon*/
	}
	/**
	 * La methode run() est appeler automatiquement avec l'instance Accepter_client.start() 
	 */
	public void run() {
		/**
		 * la requete reçue
		 * */
		String msg;
		try
		{
			/**La première lecture*/
			msg = this.fluxEntrant.readLine();
			System.out.println("Requête reçu: "+msg);
			/** appelle de la methode qui segement les infos de la fenetre*/
			informationDeLaFenetre(msg);
			/**On transmet à la fenetre les infos*/
			Fenetre fenetre = new Fenetre(titre, this.tab_cordonne[0], this.tab_cordonne[1], 
													this.tab_cordonne[2], this.tab_cordonne[3]);
			
			/**
			 * <b>Declaration des maillons :</b>
			 * <p>Construction de la chaine, à chaque declaration, ici segement point sur cercle; cercle point sur le polygone 
			 * et polygon sur un pointeur null</p>
			 */
			StringDrawCOR polygone = new PolygonDraw(null);
			StringDrawCOR cercle  = new CercleDraw(polygone);
			StringDrawCOR segment  = new SegmentDraw(cercle);
			
			while(true)
			{
				/**
				 * on boucle sur les requêtes reçu 
				 */
				msg = this.fluxEntrant.readLine();
				System.out.println("Requête reçu: "+msg);
				
				/**
				 * On donne à la chaine chaque requête reçu
				 */
				segment.operation(fenetre,msg); 
				/**
				 * On affiche la fenetre
				 */
				fenetre.strategie.show();
				fenetre.graphics.dispose();
				/**
				 * si le tempon est vide on sort de la boucle
				 */
				if (msg == null) break; 
			}
			
		}
		catch (SocketException e) {
			// TODO: handle exception
			System.out.println("session de dessin terminée par le client");
		}
		catch (NumberFormatException e) {
			e.printStackTrace();
		}
		catch(IOException e) {
			e.printStackTrace();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	/**
	 * <p>On segment la requete</p>
	 * @param msg est segmenté, set le titre et le tableau coordonne
	 */
	private void informationDeLaFenetre(String msg) {
		String l[] = msg.split(",");
		this.titre = l[0].trim();
		
		this.tab_cordonne[0] = Integer.parseInt(l[1].trim());
		this.tab_cordonne[1] = Integer.parseInt(l[2].trim());
		this.tab_cordonne[2] = Integer.parseInt(l[3].trim());
		this.tab_cordonne[3] = Integer.parseInt(l[4].trim());
	}
}
