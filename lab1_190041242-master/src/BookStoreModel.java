import java.sql.*;
public class BookStoreModel {
    /**
     * This method will essentially communicate with the backend
     * database server and get the information that the user has
     * requested and want to store.
     **/
    public Connection con;

    public BookStoreModel() {
        DBconnection();
    }
    /** This Function is used to connect the Database in
     * This is application I am using the MysqlWorkbench**/
    public void DBconnection()
    {
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
            con=DriverManager.getConnection("jdbc:mysql://localhost:3306/CSE_4636_LAB1_DB","root","admin123");
            /** here CSE_4636_LAB1_D is database name, root is username and is admin123 password **/
        }catch(Exception e){ System.out.println(e);}
    }

    /**This function is used to add a book the database**/
    public boolean addBook(BookStoreView View)
    {
        int rowAffected=0;
        try {
            String query = "INSERT INTO BookStoreTB(title , author , publisher , publishingdate) VALUES(?,?,?,?)";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1,View.getBookTitle());
            pstmt.setString(2,View.getAuthor());
            pstmt.setString(3,View.getPublisher());
            pstmt.setString(4,View.getPublishingDate());
            rowAffected = pstmt.executeUpdate();
        }catch (Exception e){
            System.out.println(e);
        }
        return rowAffected == 1 ;
    }

    /**This function is used to delete a book the database**/
    public boolean deleteBook(BookStoreView View)
    {
        int rowaffected=0;
        try
        {
            String query = "DELETE FROM BookStoreTB WHERE title = ? ";
            PreparedStatement statement = con.prepareStatement(query);
            statement.setString(1,View.getBookTitle());
            rowaffected = statement.executeUpdate();

        }catch (Exception e)
        {
            System.out.println(e);
        }
        return rowaffected == 1;
    }

    /**This function is used to retrieve a specific book information from the database**/
    public ResultSet viewDetailsOfSpecificBook(BookStoreView view)
    {
        try
        {
            String query = "SELECT title , author , publisher , publishingdate from BookStoreTB where title = ?";
            PreparedStatement statement = con.prepareStatement(query);
            statement.setString(1,view.getBookTitle());
            ResultSet rs = statement.executeQuery();
            return rs;
        }catch (Exception e)
        {
            System.out.println(e);
        }
        return null;
    }
    /**This function is used to retrieve the information of the all books from the database**/
    public ResultSet viewAllBooks()
    {
        try
        {
            String query = "SELECT title , author , publisher , publishingdate from BookStoreTB";
            PreparedStatement statement = con.prepareStatement(query);
            ResultSet rs = statement.executeQuery();
            return rs;
        }catch (Exception e)
        {
            System.out.println(e);
        }
        return null;
    }

}


