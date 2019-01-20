package ppil;

/**
 *<b>Chaine de responsabilite </b>
 *<p>
 *cette chaine est formée des experts listés ci-dessous de façon hiérarchique dont
 *chacun dessin une forme bien spécial sur la fenêtre quelle à reçu en paramètre.
 *</p>
 *<b>Composition :</b>
 *<p>elle est composé de trois maillons</p>
 *<ul>
 *<li><b>SegmentDraw</b></li>
 *<li><b>CercleDraw </b></li>
 *<li><b>PolygonDraw</b></li>
 *</ul>
 *@see StringDrawCOR
 *@see SegmentDraw
 *@see CercleDraw
 *@see PolygonDraw
 *@see StringDraw#operation(Fenetre, String)
 */

public interface StringDraw {
	/**
	 * 
	 * @param f est la fenêtre sur la quelle le maillon expert dessine s'il arrive
	 * @param msg est les informations (coordonnées, type) de la forme qui doit être dessinée
	 * @return true si un maillon expert arrive à traite la requete reçu sinon false
	 */
	public boolean operation(Fenetre f, String msg);
}
