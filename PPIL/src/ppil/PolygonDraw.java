package ppil;

import java.awt.Color;
import java.awt.Polygon;

public class PolygonDraw extends StringDrawCOR{
	public PolygonDraw(StringDrawCOR suivant) {
		super(suivant);
		// TODO Auto-generated constructor stub
	}

	@Override
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
					f.graphics.fillPolygon(xPoints, yPoints, nPoints);
				}
			}
			else 
			{
				f.graphics.setColor(new Color(
						Integer.parseInt(requete[1].trim()),
						Integer.parseInt(requete[2].trim()),
						Integer.parseInt(requete[3].trim())
					));
				Polygon p = new Polygon();
				
				for(int i=4; i<requete.length; i=i+2)
					p.addPoint(Integer.parseInt(requete[i].trim()),
									Integer.parseInt(requete[i+1]));
				
				//affiche le polygone
				f.graphics.fillPolygon(p);
			}
			
				
				
			return true;
		}
	}

	
}
