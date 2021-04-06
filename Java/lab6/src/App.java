import java.util.Random;

import lab8.impl.Book;
import lab8.impl.Magazine;
import lab8.impl.Textbook;

// Полиграфические издания. Возможности: оформить договор; открыть\редактировать\верстать издание; 
// отправить на печать; отказаться от издания; оплатить издание; возобновить\закрыть издание. 
// Добавить специализированные методы для Книги, Журнала, Учебного пособия.
public class App {
    public static void main(String[] args) {
        Book[] books = new Book[] { new Book("Mein Kampf", new String[] { "Adolf Hitler" }),
                new Book("Inferno", new String[] { "Den Brown" }),
                new Book("Master&Margarita", new String[] { "Mihail Bulgakov" }) };

        // String[] auth = books[1].getAuthors();
        // for (int i = 0; i < auth.length; i++) {
        // System.out.println(auth[i]);
        // }

        Magazine[] magazines = new Magazine[] { new Magazine("Haker"), new Magazine("Times"), new Magazine("GQ") };

        Textbook[] textbooks = new Textbook[] {
                new Textbook("Психбольница в руках пациента", "Дизайн", new String[] { "Алан Купер" }),
                new Textbook("Нейронные сети", "NG", new String[] { "Саймон Хайкин" }),
                new Textbook("Think Julia: How to Think Like a Computer Scientist", "Programming",
                        new String[] { "Ben Lauwens", "Allen B. Downey" }) };

        // String[] auth = textbooks[2].getAuthors();
        // for (int i = 0; i < auth.length; i++) {
        // System.out.println(auth[i]);
        // }

        Random rand = new Random();
        for (Textbook textbook : textbooks) {
            textbook.drowUpContract(rand.nextInt(1000), rand.nextDouble() * 1000);
            System.out.println(textbook.getContractInfo().toString() + "\n");
        }
    }
}
