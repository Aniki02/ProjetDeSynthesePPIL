package ppil;

import java.awt.Color;

public class CercleDraw extends StringDrawCOR{

	public CercleDraw(StringDrawCOR suivant) {
		super(suivant);
		// TODO Auto-generated constructor stub
	}

	@Override
	public boolean operationSpec(Fenetre f, String msg) {
		String l[] = msg.split(",");
		if(!l[0].trim().equalsIgnoreCase("drawOval"))
		{
			System.out.println("echec fillOval: "+l[0].trim());
			return false;
		}
		else 
		{	
			System.out.println("succes fillOval: "+l[0].trim());
			int x, y,  r; 
			x = Integer.parseInt(l[4].trim());
			y = Integer.parseInt(l[5].trim());
			//System.out.println(l[6].trim());
			 r = (int)Double.parseDouble(l[6].trim());
			
			f.strategie= f.getBufferStrategy();
			f.graphics = f.strategie.getDrawGraphics();
			f.graphics.setColor(new Color(
					Integer.parseInt(l[1].trim()),
					Integer.parseInt(l[2].trim()),
					Integer.parseInt(l[3].trim())
					));
			f.graphics.fillOval(x, y, r, r);
			return true;
		}
	}

}
