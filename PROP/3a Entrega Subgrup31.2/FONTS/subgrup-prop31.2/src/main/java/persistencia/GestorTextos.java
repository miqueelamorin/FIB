package persistencia;

import com.google.gson.Gson;
import domini.Text;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Classe GestorTextos que gestiona l'emmagatzematge i la càrrega de textos utilitzant la llibreria Gson.
 */
public class GestorTextos {
    /**
     * Guarda els textos proporcionats en format JSON en un fitxer especificat pel path.
     * @param textos Mapa que conté parells de noms de textos i instàncies de Text.
     * @param path Camí del fitxer on es guardarà la informació dels textos.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant l'escriptura al fitxer.
     */
    public void guardarTextos(Map<String, Text> textos, String path) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(path));
        Gson gson = new Gson();
        for (Map.Entry<String, Text> text : textos.entrySet()) {
            String jsonText = gson.toJson(text.getValue());
            writer.write(jsonText + "\n");
        }
        writer.close();
    }

    /**
     * Carrega els textos des d'un fitxer especificat pel path i els retorna com un mapa.
     * @param path Path del fitxer on es troba la informació dels textos.
     * @return Mapa que conté parells de noms de textos i instàncies de Text carregades.
     * @throws IOException Excepció que es llança en cas d'error d'entrada/sortida durant la lectura del fitxer.
     */
    public Map<String, Text> carregarTextos(String path) throws IOException {
        Map<String, Text> textos = new HashMap<>();
        BufferedReader reader = new BufferedReader(new FileReader(path));
        Gson gson = new Gson();
        String fila;
        while ((fila = reader.readLine()) != null) {
            Text text = gson.fromJson(fila, Text.class);
            textos.put(text.getNom(), text);
        }
        return textos;
    }
}
