package persistencia;

import com.google.gson.Gson;
import domini.Alfabet;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Classe GestorAlfabets que gestiona l'emmagatzematge i la càrrega d'alfabets utilitzant la llibreria Gson
 */
public class GestorAlfabets {
    /**
     * Guarda els alfabets proporcionats en format JSON en el fitxer  especificat pel path.
     * @param alfabets Mapa que conté parells de noms d'alfabets i instàncies d'Alfabet
     * @param path Path del fitxer on es guardarà la informació dels alfabets
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant l'escriptura al fitxer.
     */
    public void guardarAlfabets(Map<String, Alfabet> alfabets, String path) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(path));
        Gson gson = new Gson();
        for (Map.Entry<String, Alfabet> alfabet : alfabets.entrySet()) {
            String jsonAlfabet = gson.toJson(alfabet.getValue());
            writer.write(jsonAlfabet + "\n");
        }
        writer.close();
    }

    /**
     * Carrega els alfabets des d'un fitxer especificat pel path i els retorna com un mapa.
     * @param path Path del fitxer on es troba la informació dels alfabets.
     * @return Mapa que conté parells de noms d'alfabets i instàncies d'Alfabet carregades.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant la lectura del fitxer.
     */
    public Map<String, Alfabet> carregarAlfabets(String path) throws IOException {
        Map<String, Alfabet> alfabets = new HashMap<>();
        BufferedReader reader = new BufferedReader(new FileReader(path));
        Gson gson = new Gson();
        String fila;
        while ((fila = reader.readLine()) != null) {
            Alfabet alfabet = gson.fromJson(fila, Alfabet.class);
            alfabets.put(alfabet.getNom(), alfabet);
        }
        return alfabets;
    }
}
