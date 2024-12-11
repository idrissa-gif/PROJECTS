const mysql = require('mysql');

// Create a database connection
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'admin123',
    database: 'blood_bank_system_db', // Your database name
    port: 3306, // Add the port property and set it to the MySQL port (default is 3306)
});

// Connect to the database
db.connect((err) => {
    if (err) {
        console.error('Error connecting to the database: ' + err.stack);
        // Handle the error (e.g., log it or exit the application)
    } else {
        console.log('Connected to the database as id ' + db.threadId);
        // Database connection successful, you can perform database operations here
    }
});

// Export the database connection
module.exports = db;
