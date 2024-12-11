// controllers/donorsController.js
const Donor = require('../models/donorModel');

const donorsController = {
  getAllDonors: (req, res) => {
    Donor.getAll((error, donors) => {
      if (error) {
        return res.status(500).json({ error: 'Database error' });
      }
      res.render('donors', { donors });
    });
  },
  
  getAddDonorPage: (req, res) => {
    res.render('add-donor'); // Assuming you have an 'add-donor' view
  },
  
   postAddDonor: (req, res) => {
    res.render("add-donor");
  },
};

module.exports = donorsController;
