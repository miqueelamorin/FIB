package domini;

import java.util.Objects;

/**
 * Aquesta Classe és l'encarregada de gestionar un Text
 **/
public class Text {
    private String contingut;
    private final String nom;

    /**
     * Constructora de la Classe
     * @param nom Nom del Text
     * @param contingut Contingut del Text
     */
    public Text(String nom, String contingut) {
        this.nom = nom;
        this.contingut = contingut;
    }

    /**
     * Retorna el nom del Text
     * @return Nom del Text
     */
    public String getNom(){ return nom; }

    /**
     * Retorna el contingut del Text
     * @return Contingut del Text
     */
    public String getContingut() {
        return contingut;
    }

    /**
     * Modifica el contingut del Text
     * @param t Contingut del Text
     */
    public void setContingut(String t) {
        contingut = t;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Text text = (Text) o;
        return Objects.equals(nom, text.nom);
    }
}
