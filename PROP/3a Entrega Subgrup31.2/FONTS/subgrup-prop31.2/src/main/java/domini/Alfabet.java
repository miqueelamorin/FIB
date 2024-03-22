package domini;

import java.util.Set;

/**
 * Aquesta Classe representa un Alfabet
 */
public class Alfabet{
    private Set<Character> caracters;
    private String nom;

    /**
     * Constructora de la classe Alfabet
     * @param nom Nom de l'alfabet
     * @param chars Conjunt de caràcters que formen l'alfabet
     * @throws Exception Si el conjunt de caràcters és buit
     */
    public Alfabet(String nom, Set<Character> chars) throws Exception {
        this.nom = nom;
        if(chars.isEmpty()) throw new Exception("No s'ha proporcionat cap caràcter.");
        caracters = chars;
    }

    /**
     * Constructora de la classe Alfabet
     * @return Conjunt de caràcters que formen l'alfabet
     */
    public String getNom() { return nom;}

    /**
     * Getter de caracters
     * @return Conjunt de caràcters que formen l'alfabet
     */
    public String getCaracters(){
        return this.toString();
    }

    /**
     * Setter de caracters
     * @param c Conjunt de caràcters que formen l'alfabet
     * @throws Exception Si el conjunt de caràcters és buit
     */
    public void setCaracters(Set<Character> c) throws Exception {
        if(c.isEmpty()) throw new Exception("No s'ha proporcionat cap caràcter.");
        caracters = c;
    }

    /**
     * Getter de nom
     * @param n Nom de l'alfabet
     */
    public void setNom(String n) { nom = n; }

    @Override
    public String toString(){
        StringBuilder chars = new StringBuilder();
        for (char ch : caracters) {
            chars.append(ch);
        }
        return chars.toString();
    }
}
