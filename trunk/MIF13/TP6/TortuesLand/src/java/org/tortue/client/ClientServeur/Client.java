package org.tortue.client.ClientServeur;

import java.util.ArrayList;
import org.tortue.client.Modele.Tortue;

/**
 * Le client et ses tortues
 */
public class Client {

    private String nom;

    private ArrayList<Tortue> listeTortues = new ArrayList<Tortue>();


    public Client(String nom) {
        this.nom = nom;
    }

    public void addTortue(String nomTortue){
        listeTortues.add(new Tortue(nomTortue, 0, 0));
    }

    
    public void addTortue(Tortue uneTortue){
        listeTortues.add(new Tortue(uneTortue));
    }
    
    public Tortue getTortue(int id){
        return listeTortues.get(id);
    }

    public void deleteTortue(int id){
        listeTortues.remove(id);
    }

    public String getNom() {
        return nom;
    }
    
}