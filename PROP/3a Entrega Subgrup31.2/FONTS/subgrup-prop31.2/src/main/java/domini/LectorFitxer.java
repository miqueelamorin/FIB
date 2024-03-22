package domini;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

/**
 * Aquesta Classe representa un Lector de Fitxers
 */
public class LectorFitxer {

    private static LectorFitxer instancia;

    /**
     * Constructora de la classe
     */
    private LectorFitxer(){}

    /**
     * Singleton de la classe
     * @return retorna la instancia de la classe
     */
    //##### SINGLETON ######
    public static LectorFitxer getInstance(){
        if(instancia == null){
            instancia = new LectorFitxer();
        }
        return instancia;
    }

    /**
     * Importa el contingut d'un fitxer
     * @param path path del fitxer a importar
     * @return retorna el contingut del fitxer
     * @throws Exception si el fitxer no existeix
     */
    public String importarFitxer(String path) throws Exception {

        String data;
        try {
            File file = new File(path);
            InputStream resource = new FileInputStream(file);
            //assert resource != null;
            data = new String(resource.readAllBytes());
        } catch (FileNotFoundException e) {
            throw new Exception("File Not Found.");
        }
        return data;
    }
}
