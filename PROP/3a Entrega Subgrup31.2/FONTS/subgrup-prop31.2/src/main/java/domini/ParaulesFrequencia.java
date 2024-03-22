package domini;

import java.util.*;

/**
 * Classe ParaulesFrequencia
 */
public class ParaulesFrequencia {
    private Map<String, Integer> llistaFreq;
    private final String nom;
    private Set<Text> textos = new HashSet<>();

    /**
     * Constructora de ParaulesFrequencia amb contingut
     * @param nom Nom de la llista
     * @param ll Llista de paraules amb el seu numero de repeticions
     * @throws Exception En cas de que hi hagi algun error
     */
    public ParaulesFrequencia(String nom, String ll) throws Exception {
        llistaFreq = convertirMap(ll);
        this.nom = nom;
    }

    /**
     * Constructora de ParaulesFrequencia amb textos
     * @param nom Nom de la llista
     * @param t Textos dels quals es calcularà la llista de paraules amb el seu numero de repeticions
     */
    public ParaulesFrequencia(String nom, Set<Text> t) {
        llistaFreq = creaLlistaText(textToString(t));
        textos = t;
        this.nom = nom;
    }


    /**
     * Constructora de ParaulesFrequencia buida
     * @return Retorna el nom de la llista
     */
    public String getNom(){ return nom; }

    /**
     * Getter de llistaFreq
     * @return Retorna la llista de paraules amb el seu numero de repeticions
     */
    public Map<String, Integer> getLlistaFreq() {
        return llistaFreq;
    }

    /**
     * Getter de textos
     * @return Retorna els textos dels quals es calcula la llista de paraules amb el seu numero de repeticions
     */
    public Set<Text> getTextos(){return textos;}

    /**
     * Setter de llistaFreq
     * @param llista Llista de paraules amb el seu numero de repeticions
     * @throws Exception En cas de que hi hagi algun error
     */
    public void setLlistaFreq(String llista) throws Exception {
        llistaFreq = convertirMap(llista);
    }

    /**
     * Afegeix un text
     * @param t Text dels quals es calcularà la llista de paraules amb el seu numero de repeticions
     * @throws Exception En cas de que hi hagi algun error
     */
    public void afegirText(Text t) throws Exception {
        if(textos.isEmpty()) throw new Exception("Aquesta llista no ha estat creada a partir de textos");
        textos.add(t);
        llistaFreq = creaLlistaText(textToString(textos));
    }

    /**
     * Elimina un text
     * @param t Text dels quals es calcularà la llista de paraules amb el seu numero de repeticions
     * @throws Exception En cas de que hi hagi algun error
     */
    public void eliminaText(Text t) throws Exception {
        String n = t.getNom();
        if(textos.size() == 1) throw new Exception("La llista no pot quedar buida.");
        textos.removeIf(txt -> Objects.equals(txt.getNom(), n));
        llistaFreq = creaLlistaText(textToString(textos));
    }


    /**
     * Converteix una llista de paraules amb el seu numero de repeticions en un Map
     * @param llista Llista de paraules amb el seu numero de repeticions
     * @return Retorna un Map de paraules amb el seu numero de repeticions
     * @throws Exception En cas de que hi hagi algun error
     */
    private Map<String, Integer> convertirMap(String llista) throws Exception {
        Map<String, Integer> map = new HashMap<>();

        if (llista.charAt(llista.length()-1) != '\n') llista += '\n';

        String paraula = "";
        String numero = "";
        boolean recollintp = true;

        for (int i = 0; i < llista.length(); ++i){
            char a = llista.charAt(i);
            if (recollintp){
                if (a == ':') recollintp = false;
                else if (Character.isLetter(a)) paraula += a;
                else throw new Exception("Format incorrecte");
            }
            else{
                if (a == '\n') {
                    map.put(paraula, Integer.parseInt(numero));
                    recollintp = true;
                    paraula = numero = "";
                }
                else if (Character.isDigit(a)) numero += a;
                else throw new Exception("Format incorrecte");
            }
        }


        return map;
    }

    /**
     * Crea una llista de paraules amb el seu numero de repeticions a partir d'un text
     * @param text Text dels quals es calcularà la llista de paraules amb el seu numero de repeticions
     * @return Retorna un Map de paraules amb el seu numero de repeticions
     */
    private Map<String, Integer> creaLlistaText(String text) {
        //Divido el texto en palabras
        String[] paraules = text.split("[\\s,.;:]+");
        Map<String, Integer> map = new HashMap<>();

        for (String paraula : paraules) {
            paraula = paraula.toLowerCase();
            int valor = map.getOrDefault(paraula, 0);
            map.put(paraula, valor + 1);
        }
        return map;

    }

    /**
     * Uneix els textos en un String
     * @param t Textos dels quals es calcularà la llista de paraules amb el seu numero de repeticions
     * @return Retorna un String amb tots els textos
     */
    private String textToString(Set<Text> t){
        StringBuilder unio_textos = new StringBuilder();
        this.textos = t;
        for (Text s : this.textos){
            String text = s.getContingut();
            if(!text.endsWith("\n")){
                text += '\n';
            }
            unio_textos.append(text);
        }
        return unio_textos.toString();
    }

    /**
     * Retorna la llista de paraules amb el seu numero de repeticions
     * @return Retorna un String amb la llista de paraules amb el seu numero de repeticions
     */
    @Override
    public String toString(){
        StringBuilder freqs = new StringBuilder();
        for(HashMap.Entry<String, Integer> entry : llistaFreq.entrySet()){
            freqs.append(entry.getKey()).append(": ").append(entry.getValue()).append('\n');
        }
        return freqs.deleteCharAt(freqs.length()-1).toString();
    }
}