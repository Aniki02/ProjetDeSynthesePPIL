package ppil;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.SocketException;

public class Accepter_client extends Thread {
	private Socket socket;
	private BufferedReader fluxEntrant;
	
	private String titre;
	private int tab_cordonne[]=new int[4];
	
	public Accepter_client(Socket socket) throws IOException{
		this.socket = socket;
		this.fluxEntrant= new BufferedReader(new InputStreamReader(socket.getInputStream()));
	}
	
	public void run() {
		String msg;
		try
		{
			msg = this.fluxEntrant.readLine();
			System.out.println("Requête reçu: "+msg);
			informationDeLaFenetre(msg);
			Fenetre fenetre = new Fenetre(titre, this.tab_cordonne[0], this.tab_cordonne[1], 
													this.tab_cordonne[2], this.tab_cordonne[3]);
			
			StringDrawCOR polygone = new PolygonDraw(null);
			StringDrawCOR cercle  = new CercleDraw(polygone);
			StringDrawCOR segment  = new SegmentDraw(cercle);
			
			while(true)
			{
				msg = this.fluxEntrant.readLine();
				System.out.println("Requête reçu: "+msg);
				
				
				segment.operation(fenetre,msg);
				
				fenetre.strategie.show();
				fenetre.graphics.dispose();
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
	
	private void informationDeLaFenetre(String msg) {
		String l[] = msg.split(",");
		this.titre = l[0].trim();
		
		this.tab_cordonne[0] = Integer.parseInt(l[1].trim());
		this.tab_cordonne[1] = Integer.parseInt(l[2].trim());
		this.tab_cordonne[2] = Integer.parseInt(l[3].trim());
		this.tab_cordonne[3] = Integer.parseInt(l[4].trim());
	}
}
