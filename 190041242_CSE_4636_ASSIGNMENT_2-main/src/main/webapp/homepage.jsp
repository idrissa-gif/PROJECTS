<%@ page import="java.*" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.Arrays" %>
<%@ page import="java.io.PrintWriter" %>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Home Page</title>
</head>
<body>
<h1>Welcome to your Online Shopping Website</h1>
<h2 align="center"> List of Products </h2>
<%
    ArrayList<ArrayList<String>> products = new ArrayList<>();
    products.add(new ArrayList<>(Arrays.asList("1","Bluetooh Adaptor","$103")));
    products.add(new ArrayList<>(Arrays.asList("2","USB cable","$23")));
    products.add(new ArrayList<>(Arrays.asList("3","Raspberry pi","$230")));
    products.add(new ArrayList<>(Arrays.asList("4","Ardino pico","$12")));
    products.add(new ArrayList<>(Arrays.asList("5","Addidas Sneaker","$130")));
    out.print(
            "<table  border = \"1\" align = \"center\"> " +
            "<tr>" +
            "       <th>Item Id</th> " +
            "       <th>Item Name</th> " +
            "       <th>Price</th>" +
            "       <th>Option</th>" +
            "</tr>");
    for (int i =0  ; i<products.size() ; i++)
    {
        out.println("<form action=\"addToCart\"><tr>"+
                        "<td > <input name=\"ItemId\" value="+ products.get(i).get(0) + " readonly></td>" +
                        "<td > <input name=\"ItemName\" value="+ products.get(i).get(1) + " readonly></td>" +
                        "<td > <input name=\"price\" value=" + products.get(i).get(2) +" readonly></td>"+
                        "<td> <button type=\"submit\">ADD TO CART </button> </td>"+

                "</tr></form>");
    }
    out.println("</table>");
%>



<form action="logout" method="post"  align="center" >
    <button type="submit">Logout</button>
</form>

<form action="viewCart" align="center" >
    <button type="submit">View Your Cart</button>
</form>
</body>
</html>