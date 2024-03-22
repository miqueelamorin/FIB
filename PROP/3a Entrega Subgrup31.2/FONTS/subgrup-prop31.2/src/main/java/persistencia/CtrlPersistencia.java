package persistencia;

import domini.*;

import java.io.IOException;

/**
 * Classe CtrlPersistencia encarregada de gestionar la comunicació amb la capa de domini
 */
public class CtrlPersistencia {
    private final String BASE_PATH = "dades/";
    private final GestorAlfabets gestorAlfabets = new GestorAlfabets();
    private final GestorTextos gestorTextos = new GestorTextos();
    private final GestorParaulesFrequencia gestorParaulesFrequencia = new GestorParaulesFrequencia();
    private final GestorParellsLletres gestorParellsLletres = new GestorParellsLletres();
    private final GestorTeclats gestorTeclats = new GestorTeclats();
    private static CtrlPersistencia instancia;

    /**
     * @return Retorna la instància del CtrlDomini
     */
    public static CtrlPersistencia getInstance() {
        if (instancia == null) {
            instancia = new CtrlPersistencia();
        }
        return instancia;
    }

    /**
     * Guarda tots els objectes de tipus Teclat, Text, Alfabet, ParaulesFrequencia i ParellsLletres que conté el DTO.
     * @param dto DTO que conté tots els objectes que volem guardar a fitxers de text pla.
     * @throws IOException Llança una excepció en cas que no es pugui escriure a un fitxer.
     */
    public void guardarDades(DadesDTO dto) throws IOException {
        String pathAlfabets = BASE_PATH + "alfabets";
        gestorAlfabets.guardarAlfabets(dto.getAlfabets(), pathAlfabets);

        String pathTextos = BASE_PATH + "textos";
        gestorTextos.guardarTextos(dto.getTextos(), pathTextos);

        String pathParaulesFrequencia = BASE_PATH + "paraulesFrequencia";
        gestorParaulesFrequencia.guardarParaulesFrequencia(dto.getParaulesFrequencia(), pathParaulesFrequencia);

        String pathParellsLletres = BASE_PATH + "parellsLletres";
        gestorParellsLletres.guardarParellsLletres(dto.getParellsLletres(), pathParellsLletres);

        String pathTeclats = BASE_PATH + "teclats";
        gestorTeclats.guardarTeclats(dto.getTeclats(), pathTeclats);
    }

    /**
     * Carrega tots els objectes de tipus Teclat, Text, Alfabet, ParaulesFrequencia i ParellsLletres guardats en fitxers.
     * @return Retorna un DTO amb tots els objectes guardats en fitxers de text pla.
     * @throws IOException Llança una excepció en cas que no es pugui llegir un fitxer.
     */
    public DadesDTO carregarDades() throws IOException {
        DadesDTO dto = new DadesDTO();
        String pathAlfabets = BASE_PATH + "alfabets";
        dto.setAlfabets(gestorAlfabets.carregarAlfabets(pathAlfabets));

        String pathTextos = BASE_PATH + "textos";
        dto.setTextos(gestorTextos.carregarTextos(pathTextos));

        String pathParaulesFrequencia = BASE_PATH + "paraulesFrequencia";
        dto.setParaulesFrequencia(gestorParaulesFrequencia.carregarParaulesFrequencia(pathParaulesFrequencia));

        String pathParellsLletres = BASE_PATH + "parellsLletres";
        dto.setParellsLletres(gestorParellsLletres.carregarParellsLletres(pathParellsLletres));

        String pathTeclats = BASE_PATH + "teclats";
        dto.setTeclats(gestorTeclats.carregarTeclats(pathTeclats));

        return dto;
    }
}
