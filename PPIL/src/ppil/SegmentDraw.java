package ppil;

import java.awt.Color;
/**
 * <b>Ce maillon qui dessine un segment</b>
 * <p>Elle possede deux methodes, voir ci-dessous.</p>
 * @see SegmentDraw#SegmentDraw(StringDrawCOR)
 * @see SegmentDraw#operationSpec(Fenetre, String)
 *
 */
public class SegmentDraw extends StringDrawCOR{
	/**
	 * @param suivant un maillon suivant
	 */
	public SegmentDraw(StringDrawCOR suivant) {
		super(suivant);
	}
	@Override
	/**
	 * @param f la fenetre sur la quelle on dessine
	 * @param msg la forme à dessiner
	 * <p>elle traite uniquement une forme segment.</>
	 * <p>
	 * 		on segmente(split) la forme reçu en chaine de caratère possedant un separateur virgule dans un tableau l;
	 * 		on teste si le type est different de drawLine(segment) on renvoi false
	 * 		sinon on traite.
	 * </p>
	 * @return true s'il arrive à traiter sinon false
	 * 
	 */
	protected boolean operationSpec(Fenetre f, String msg) {
		// TODO Auto-generated method stub
		String l[] = msg.split(",");
		if(!l[0].trim().equalsIgnoreCase("drawLine"))/** si */
		{
			System.out.println("echec drawLine: "+l[0].trim());
			return false;
		}
		else 
		{	
			System.out.println("succes drawLine: "+l[0].trim());
			int x, y, W, H;
			
			x = Integer.parseInt(l[4].trim());
			y = Integer.parseInt(l[5].trim());
			W = Integer.parseInt(l[6].trim());
			//System.out.println(l[6].trim());
			H = Integer.parseInt(l[7].trim());
			
			f.strategie= f.getBufferStrategy();
			f.graphics = f.strategie.getDrawGraphics();
			f.graphics.setColor(new Color(
					Integer.parseInt(l[1].trim()),
					Integer.parseInt(l[2].trim()),
					Integer.parseInt(l[3].trim())
					));
			f.graphics.drawLine(x, y, W, H);/**dessine sur la fenêtre*/
			return true;
		}
	}
	
	
}
