package Vue;

import Model.Joueur;
import Model.Terrain;
import ObservListe.Observateur;
import java.applet.Applet;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.util.ArrayList;


/**
 * Cette classe affiche le terrain et son contenu
 */
public class VueTerrain extends Applet {

    Terrain unTerrain;

    ArrayList<VueJoueur> listeVueJoueurs;

    /**
     * Initialisation des valeurs de la vue du terrain
     * @param unTerrain leTerrain provenant du model
     * @param listeJoueurs la liste de tous les joueurs du model
     */
    public VueTerrain(Terrain unTerrain, ArrayList<Joueur> listeJoueurs) {

        this.unTerrain = unTerrain;

        listeVueJoueurs =  new ArrayList<VueJoueur>();

        setBackground(Color.white);
        setPreferredSize(new Dimension(Terrain.LONGUEUR,Terrain.LARGEUR));

        //chaqu joueur du model aura une vue
        for(int i = 0; i < listeJoueurs.size(); i++){
            listeVueJoueurs.add(new VueJoueur(this, listeJoueurs.get(i)));

            //le terrain observe chaque joueur
            listeJoueurs.get(i).ajouterObservateur(new Observateur() {

                public void miseAJour() {
                    
                    if (isOpaque()) resetBackground();
                    dessiner(getGraphics());
                    
                }
            });
        }
        
    }


    /**
     * Redessine le fond du terrain
     */
    private void resetBackground(){
        Graphics g = getGraphics();
        Color c = g.getColor();
        g.setColor(Color.white);
        g.fillRect(0,0,Terrain.LONGUEUR,Terrain.LARGEUR); //cadre blanc de fond
        dessinerTerrain();
    }

    private void dessinerTerrain(){

        int longueur = Terrain.LONGUEUR;
        int largeur = Terrain.LARGEUR;

        int longueurCage = 50;
        int largeurCage = 10;

        Graphics g = getGraphics();
        g.setColor(Color.GRAY); //on dessine les traits en noir

        //Gauche
        g.drawRect(-1, (largeur/2) - longueurCage, largeurCage, 2*longueurCage);
        g.drawRect(longueur + 1 - largeurCage, (largeur/2) - longueurCage, largeurCage, 2*longueurCage);

        g.drawLine(longueur/2, 0, longueur/2, largeur );
        
        drawOvale();

    }



    /**
     * Dessine les joueurs
     * @param g contexte graphique ne connaissant rien du précédant
     */
    public void dessiner(Graphics g) {

        for(int i = 0; i < listeVueJoueurs.size(); i++)
            listeVueJoueurs.get(i).dessiner(g);

        g.dispose(); //relachement du context graphique

        super.paintComponents(getGraphics());

    }

}