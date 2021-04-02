package pack;

import java.util.*;

enum Currency{
    USD,
    EUR,
    RUB,
    BYN,
    GBP
}

enum Status{
    ACTIVE,
    BLOCKED
}

public class Client extends Person
{
    public class Account
    {
        private String id;
        private Double amount = new Double(0.0);
        private Status status = Status.ACTIVE;
        private boolean overdrivable;
        private Currency currency;

        public Account(double initMoney, Currency cur, boolean over)
        {
            amount = initMoney;
            currency = cur;

            id = idGen();

            overdrivable = over;
        }

        private String idGen()
        {
            Random rand = new Random();
            StringBuilder sb = new StringBuilder();

            sb.append(rand.nextInt(8999) + 1000);
            sb.append(rand.nextInt(8999) + 1000);
            sb.append(rand.nextInt(8999) + 1000);
            sb.append(rand.nextInt(8999) + 1000);

            return sb.toString();
        }

        public void setStatus(Status st)
        {
            status = st;
        }

        public String getId()
        {
            return id;
        }

        public Double getAmount()
        {
            return amount;
        }

        public Currency getCurrency()
        {
            return currency;
        }

        public Status getStatus()
        {
            return status;
        }

        public void changeAmount(double money) throws Exception
        {
            if (!overdrivable && amount + money < 0)
            {
                throw new Exception("Card overdrive");
            }

            amount += money;
        }

        public void changeCurrency(Currency newCur, double convert)
        {
            currency = newCur;
            amount *= convert;
        }

        public String getAccountInfo()
        {
            StringBuilder sb = new StringBuilder();

            sb.append("\tId: " + getId() + "\n");
            sb.append("\tCurrency: " + getCurrency() + "\n");
            sb.append("\tAmount: " + String.format("%,.2f", getAmount()) + "\n\n");

            return sb.toString();
        }
    }

    private static int ID = 1;
    private final int id = ID;
    private ArrayList<Account> accounts;

    public Client(String name, String surname, Date birthday, Sex s) {
        super(name, surname, birthday, s);
        ID++;

        accounts = new ArrayList<>();
    }

    public void newAccount(double initMoney, Currency cur, boolean over)
    {
        accounts.add(new Account(initMoney, cur, over));
    }
    public void newAccount(double initMoney, Currency cur)
    {
        accounts.add(new Account(initMoney, cur, true));
    }

    public int getId()
    {
        return id;
    }

    public String getPerson()
    {
        StringBuilder sb = new StringBuilder();

        sb.append("Name: ");
        sb.append(getFirstname() + " ");
        sb.append(getSecondname() + " ");
        sb.append("\n");

        sb.append("Sex: ");
        sb.append(getSex() + "\n");

        sb.append("Birth: ");
        sb.append(getBirth() + "\n");

        for (Account ac: accounts)
        {
            sb.append(ac.getAccountInfo());
        }

        return sb.toString();
    }

    public double wholeSum(Currency cur)
    {
        double sum = 0.0;
        for (Account ac: accounts)
        {
            if (ac.currency == cur)
                sum += ac.getAmount();
        }

        return sum;
    }

    public double[] sums(Currency cur)
    {
        double[] sum = { 0.0, 0.0 };
        for (Account ac: accounts)
        {
            if (ac.currency == cur)
            {
                double money = ac.getAmount();
                if (money > 0)
                    sum[1] += money;
                else
                    sum[0] += money;
            }
        }

        return sum;
    }

    public void sortAccs()
    {
        accounts.sort(new Comparator<Account>() {
            @Override
            public int compare(Account left, Account right) {
                return left.amount.compareTo(right.amount);
            }
        });
    }

    public String[] accs()
    {
        String[] a = new String[accounts.size()];
        for (int i = 0; i < accounts.size(); ++i)
        {
            a[i] = accounts.get(i).id;
        }

        return a;
    }

    public ArrayList<String> find(Currency cur)
    {
        ArrayList<String> arr = new ArrayList<>();
        for (Account acc: accounts)
        {
            if (acc.currency == cur)
                arr.add(acc.id);
        }

        return arr;
    }
}
