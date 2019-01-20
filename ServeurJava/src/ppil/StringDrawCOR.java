package ppil;
/**
 * <b>Class abstract : qui implements StringDraw</b>
 * <p></p>
 *
 *@see StringDrawCOR#operationSpec(Fenetre, String)
 */
public abstract class StringDrawCOR implements StringDraw{
	/**
	 *@see StringDrawCOR#StringDrawCOR(StringDrawCOR)
	 */
	protected StringDrawCOR _suivant;
	
	/**
	 * 
	 *@param suivant les maillon.
	 *<p><b>Constructeur : </b>Ajoute un nouveau maillon dans chaine</p>
	 */
	public StringDrawCOR(StringDrawCOR suivant) {
		this._suivant = suivant;
	}
	
	/**
	 * Ce charge de passer la forme d'un maillon à l'autre.
	 * @param f la fenêtre sur la quelle on dessine.
	 * @param msg  la forme en chaine de caratère.
	 * @return true si la forme à puis être traitée sinon false.
	 */
	public boolean operation(Fenetre f, String msg) {
		/**
		 * <i>du premier maillon au traiteur trouver ou non on lui donne la fenêtre et la forme à traité (dessinée).</i>
		 */
		if(operationSpec(f, msg))
			return true;
		else
			/**
			 * <i>s'il existe un expert suivant.</i>
			 */
			if(this._suivant!=null)
				/**
				 * <i>on lui passe la forme à traiter</i>
				 */
				return this._suivant.operation(f, msg);
			else 
				return false; /**<i>si retourne false : c'est que aucun expert a réussi à dessiner.</i>*/
	}
	/**
	 * <p> la methodes qui sera definie pas chaques maillons :</p>
	 * @param f la fenêtre
	 * @param msg  la forme en string
	 * @return true si succès sinon false.
	 */
	protected abstract boolean operationSpec(Fenetre f, String msg);
}
