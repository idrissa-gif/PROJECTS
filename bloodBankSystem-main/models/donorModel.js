// models/donor.js
const db = require('../config/db');

const Donor = {
  getAll: (callback) => {
    db.query('SELECT * FROM donors', (error, results) => {
      if (error) {
        return callback(error, null);
      }
      return callback(null, results);
    });
  },
};

module.exports = Donor;
