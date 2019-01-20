package ppil;

import java.awt.Color;
import java.awt.Polygon;
/**
 * <b>Maillon Polygone</b>
 * <p>Dessine un polygone sur la fenêtre</p>
 * @see PolygonDraw#operationSpec(Fenetre, String)
 * @see PolygonDraw#PolygonDraw(StringDrawCOR)
 *
 */
public class PolygonDraw extends StringDrawCOR{
	/**
	 * <p>Le constructeur</p>
	 * @param suivant ajoute un suivant maillon
	 */
	public PolygonDraw(StringDrawCOR suivant) {
		super(suivant);
		// TODO Auto-generated constructor stub
	}

	@Override
	/**
	 * @param f la fenetre
	 * @param msg la requete (forme)
	 * <p>si polygone:
	 * après la segmentation de la requete si la taille de requete (tableau) egale 11 on sait que c'est un triangle, donc 
	 * on dessine un triangle, sinon on dessine le nomblre de points passer.</p>
	 */
	protected boolean operationSpec(Fenetre f, String msg) {
		// TODO Auto-generated method stub
		String requete[] = msg.split(",");
		if(!requete[0].trim().equalsIgnoreCase("drawPolygon"))
		{
			System.out.println("echec fillPolygon: "+requete[0].trim());
			return false;
		}
		else
		{
			System.out.println("succes fillPolygon: "+requete[0].trim());
			f.strategie= f.getBufferStrategy();
			f.graphics = f.strategie.getDrawGraphics();
			if(requete.length == 11)
			{
				f.graphics.setColor(new Color(
						Integer.parseInt(requete[2].trim()),
						Integer.parseInt(requete[3].trim()),
						Integer.parseInt(requete[4].trim())
					));
				int nPoints = Integer.parseInt(requete[1].trim());
				if( nPoints == 3) 
				{
					int[] xPoints = {
							Integer.parseInt(requete[5].trim()),
							Integer.parseInt(requete[6].trim()),
							Integer.parseInt(requete[7].trim())
					};
					int[] yPoints = {
							Integer.parseInt(requete[8].trim()),
							Integer.parseInt(requete[9].trim()),
							Integer.parseInt(requete[10].trim())
					};
					f.graphics.fillPolygon(xPoints, yPoints, nPoints);/**<i>on dessine un triangle</i>*/
				}
			}
			else 
			{
				f.graphics.setColor(new Color(
						Integer.parseInt(requete[1].trim()),
						Integer.parseInt(requete[2].trim()),
						Integer.parseInt(requete[3].trim())
					));
				/**on cree une instance de polygone*/
				Polygon p = new Polygon();
				/**pour chaque point on ajouter à la polygone (instance p)*/
				for(int i=4; i<requete.length; i=i+2)
					p.addPoint(Integer.parseInt(requete[i].trim()),
									Integer.parseInt(requete[i+1]));
				
				/**affiche le polygone*/
				f.graphics.fillPolygon(p);
			}
			
				
				
			return true;
		}
	}

	
}
