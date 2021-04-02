package pack;

import java.util.Date;

enum Sex {
    MALE,
    FEMALE
}

public class Person
{
    private String firstname;
    private String secondname;
    private Date birth;
    private Sex sex;

    public Person(String name, String surname, Date birthday, Sex s)
    {
        firstname = name;
        secondname = surname;
        birth = birthday;
        sex = s;
    }

    public String getFirstname()
    {
        return firstname;
    }

    public String getSecondname()
    {
        return secondname;
    }

    public Date getBirth()
    {
        return birth;
    }

    public Sex getSex()
    {
        return sex;
    }

    public void setFirstname(String firstname)
    {
        this.firstname = firstname;
    }

    public void setSecondname(String secondname)
    {
        this.secondname = secondname;
    }
}
