package ppil;

import java.awt.Dimension;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.Toolkit;
import java.awt.image.BufferStrategy;

public class Fenetre extends Frame{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public Graphics graphics;      // pour dessiner sur this
	public BufferStrategy strategie;
	/**
	 * @param titre : titre de la fenêtre
	 * @param ox : abscisse souhaité pour le bord gauche de la fenêtre
	 * @param oy : ordonnée souhaitée pour le bord supérieur de la fenêtre
	 * @param largeur : largeur souhaitée pour la fenêtre
	 * @param hauteur : hauteur souhaitée pour la fenêtre
	 * 
	 * l'unité pour ces 4 paramètres est le pixel 
	 * 
	 * */
	public Fenetre(String titre, int ox, int oy, int largeur, int hauteur) throws InterruptedException
	{
		super(titre);	
		Toolkit tk = Toolkit.getDefaultToolkit();
		int le, he; 
	
		Dimension dim = tk.getScreenSize(); 
	
		le = (int) dim.getWidth();
		he = (int) dim.getHeight();
	
		int bordGauche, bordSupérieur, l, h ;
	
		bordGauche = Math.max(0, ox);
		bordSupérieur = Math.max(0, oy);
		l = Math.min(largeur, le - bordGauche);
		h = Math.min(hauteur, he - bordSupérieur);
		this.setBounds(bordGauche, bordSupérieur, l, h);
		
		this.setVisible(true);
		
		this.setIgnoreRepaint(true);
		int nombreBuffers = 1;
		 this.createBufferStrategy(nombreBuffers);
		Thread.sleep(200);   
		//this.strategie= this.getBufferStrategy();
		//this.graphics =this.strategie.getDrawGraphics();
	}
}
