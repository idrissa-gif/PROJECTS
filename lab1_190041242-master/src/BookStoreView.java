import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

public class BookStoreView {
    private String BookTitle ;
    private String Author;
    private String Publisher;
    private String PublishingDate;
    /**
     * This method is used by controller to get the choice that the
     * user want.
     **/
    public int menu()
    {
        System.out.println("\n\nWELCOME THE BOOKSTORE WHERE USER CAN MANAGE IT BOOKS");
        System.out.println("1. ADD A NEW BOOK");
        System.out.println("2. DELETE A BOOK");
        System.out.println("3. VIEW THE DETAILS OF SPECIFIC BOOK");
        System.out.println("4. VIEW ALL THE BOOKS");
        System.out.println("5. EXIT");

        int choice = new Scanner(System.in).nextInt();
        return choice;
    }
    /**
     * This method is used by controller to update the view after a book is added in the book list
     * of the user.
     **/
    public void updateViewAfterAddBook(boolean added)
    {
        if(added == true)
        {
            System.out.println("Book Successfully Added "+this.getBookTitle()+"\n");
        }
        else {
            System.out.println("Failed to add the Book");
        }
    }
    /**
     * This method is used by controller to update the view after a book is deleted from the book list
     * of the user.
     **/
    public void updateViewAfterDeleteBook(boolean deleted)
    {
        if(deleted == true)
        {
            System.out.println("Book Successfully Deleted "+ this.getBookTitle()+"\n");
        }else
            System.out.println("Failed to remove the boook from the Book Store");
    }
    /**
     * This method is used by controller to update the view after a user request for the info of
     * specific book in the bookstore
     **/
    public void updateViewAfterViewOfSpecificBook(ResultSet rs) throws SQLException {
        if (!rs.next())
        {
            System.out.println(this.getBookTitle()+ " is not in your Book Store");
        }else {

            System.out.format("%18s %18s %18s %18s\n", "Title", "Author", "Publisher", "Publication Date");
            do {
                System.out.format("%18s %18s %18s %18s\n", rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4));
            }while (rs.next());
        }
    }
    /**
     * This method is used by controller to update the view after a user request for the info of
     * all book in the bookstore
     **/
    public void updateViewAfterViewAllBooks(ResultSet rs) throws SQLException {
        if (!rs.next())
        {
            System.out.println(this.getBookTitle()+ " is not in your Book Store");
        }else {

            System.out.format("%18s %18s %18s %18s\n", "Title", "Author", "Publisher", "Publication Date");
            do {
                System.out.format("%18s %18s %18s %18s\n", rs.getString(1), rs.getString(2), rs.getString(3), rs.getString(4));
            }while (rs.next());
        }
    }
    /**
     * This method is used by controller to get the book that the
     * user entered.
     **/
    public void setBookInfo()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("---------------------------------------------BOOK INFORMATION---------------------------------------------------");
        System.out.printf("Book Title:");
        this.BookTitle = sc.nextLine();
        System.out.printf("Book Author:");
        this.Author = sc.nextLine();
        System.out.printf("Book Publisher:");
        this.Publisher = sc.nextLine();
        System.out.printf("Publication Date:");
        this.PublishingDate = sc.nextLine();
    }


    /**
     * These methods are used by controller to get and set the attributs of the books.
     **/
    public void setBookTitle() {
        System.out.printf("Enter the Title of the Book:");
        this.BookTitle = new Scanner(System.in).nextLine();
    }
    public String getBookTitle() {
        return BookTitle;
    }

    public String getAuthor() {
        return Author;
    }

    public String getPublisher() {
        return Publisher;
    }

    public String getPublishingDate() {
        return PublishingDate;
    }




}
