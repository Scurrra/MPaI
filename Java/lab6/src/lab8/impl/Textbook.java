package lab8.impl;

import java.io.File;
import java.util.Arrays;

import lab8.PrintingPublicationAction;

public class Textbook implements PrintingPublicationAction {
    private String name, subject;
    private String[] authors;

    public Textbook(String name, String subject, String[] authors) {
        this.name = name;
        this.authors = authors;
    }

    public String getName() {
        return name;
    }

    public String getSubject() {
        return subject;
    }

    public String[] getAuthors() {
        return authors;
    }

    private int curAmount = 0;
    private double curPrice = 0.0, curSum = 0.0;
    private File file;

    @Override
    public StringBuilder getContractInfo() {
        StringBuilder sb = new StringBuilder();

        sb.append("\tTextbook name: " + name + "\n");
        sb.append("\tSubject" + subject + "\n");
        sb.append("\tAuthors: " + Arrays.toString(authors) + "\n");

        sb.append("\tCurrent contract\n");
        sb.append("\t\tAmount: " + curAmount + "\n");
        sb.append("\t\tPrice per copy: " + String.format("$%.2f", curPrice) + "\n");
        sb.append("\t\tSum of contract: " + String.format("$%.2f", curSum) + "\n");

        return sb;
    }

    @Override
    public void drowUpContract(int amount, double price) {
        curAmount = amount;
        curPrice = price;

        curSum = curPrice * curAmount;
    }

    @Override
    public void setFile(String filename) {
        file = new File(filename);
    }

    @Override
    public File open() {
        return file;
    }

    @Override
    public void print(int amountOfCopies) throws Exception {
        if (amountOfCopies <= curAmount) {
            curAmount -= amountOfCopies;
            if (amountOfCopies != 1) {
                System.out.println(amountOfCopies + " copies of the " + name + " were printed");
            } else {
                System.out.println("1 copy of the " + name + " was printed");
            }
        } else {
            throw new Exception("To many books for printing");
        }
    }

    @Override
    public void print(int amountOfCopies, int[] pages) throws Exception {
        System.out
                .println(amountOfCopies + " copies of pages " + pages.toString() + " of the " + name + " were printed");
    }

    @Override
    public void print(int amountOfCopies, int firstPage, int lastPage) throws Exception {
        if (firstPage < lastPage) {
            System.out.println(amountOfCopies + " copies of pages between " + firstPage + " and " + lastPage
                    + " of the " + name + " were printed");
        } else {
            throw new Exception("Wrong page numbers");
        }
    }

    @Override
    public void terminateContract() {
        curAmount = 0;
        curPrice = 0.0;
        curSum = 0.0;
    }

    @Override
    public void pay() {
        if (curSum != 0) {
            curSum = 0;
            System.out.println("Contract were paid");
        } else {
            System.out.println("Contract is already paid");
        }
    }
}
