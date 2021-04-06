package lab8;

import java.io.File;

public interface PrintingPublicationAction {
    StringBuilder getContractInfo();

    void drowUpContract(int amount, double price);

    void setFile(String filename);

    File open(); // просто возращает файл

    void print(int amountOfCopies) throws Exception;

    void print(int amountOfCopies, int[] pages) throws Exception;

    void print(int amountOfCopies, int firstPage, int lastPage) throws Exception;

    void terminateContract();

    void pay();
}
