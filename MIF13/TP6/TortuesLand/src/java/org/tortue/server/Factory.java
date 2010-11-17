package org.tortue.server;

import org.tortue.client.Modele.Terrain;

/**
 *
 */
public class Factory {

    private static ListeClients listeClients = new ListeClients();
    private static Terrain unTerrain = new Terrain(500,500);


    /**
     * L'application démarre quand le premier client arrive
     * @param nom le nom du premier client
     */
    public Factory() {}

    public static ListeClients getListeClients() {
        return listeClients;
    }

    public static void setListeClients(ListeClients listeClients) {
        Factory.listeClients = listeClients;
    }

    public Terrain getUnTerrain() {
        return unTerrain;
    }

    public void setUnTerrain(Terrain unTerrain) {
        Factory.unTerrain = unTerrain;
    }
}
