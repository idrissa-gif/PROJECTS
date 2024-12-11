package com.visitafrica.tonga.controller;

import com.visitafrica.tonga.model.Country;
import com.visitafrica.tonga.model.Review;
import com.visitafrica.tonga.model.Tour;
import com.visitafrica.tonga.service.ReviewService;
import com.visitafrica.tonga.service.TourService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;
import com.visitafrica.tonga.service.CountryService;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import javax.validation.Valid; // Import the Valid annotation
import com.visitafrica.tonga.model.Operator;
import com.visitafrica.tonga.service.OperatorService;
import java.util.List;


@Controller
public class TongaController {

    @Autowired
    private CountryService countryService;

    @Autowired
    private TourService tourService;

    @Autowired
    private OperatorService operatorService;

    @Autowired
    private ReviewService reviewService;

    @GetMapping("/login")
    public String login(Model model, String error, String logout) {
        if (error != null)
            model.addAttribute("error", "Your username and password is invalid.");

        if (logout != null)
            model.addAttribute("message", "You have been logged out successfully.");

        return "/login";
    }

    @PostMapping("/login")
    public String signin(Model model) {
        return "/dashboard";
    }


    @GetMapping({"/", "/welcome","/dashboard"})
    public String welcome(Model model) {
        return "/dashboard";
    }

    /** START COUNTRY FUNCTIONS **/
    @GetMapping("add-country")
    public String addCountry(Model model)
    {
        model.addAttribute("country",new Country());
        return "/Country/add-country";
    }

    @GetMapping("/addCountry")
    public String addCountry(@Valid @ModelAttribute("country") Country country,
                             BindingResult bindingResult, Model model) {
        if (bindingResult.hasErrors()) {
            model.addAttribute("message", " Failed to add Country!");
            return "/Country/add-country"; // Return back to the form if validation fails
        }

        countryService.addCountry(country); // Call the service to add the country to the database

        model.addAttribute("message", "Country added successfully!"); // Add success message to model
        return "/Country/add-country"; // Return to a success page
    }

    @GetMapping("/manage-country")
    public String manageCountry(Model model){
        List<Country> tours = countryService.findCountries();
        model.addAttribute("countries", tours);
        return "/Country/manage-country";
    }

    @GetMapping("/deleteCountry/{id}")
    public String deleteCountry(@PathVariable("id") Long id) {
        countryService.deleteCountryById(id);

        return "redirect:/manage-country"; // Redirect to the country list page after deletion
    }

    @GetMapping("/editCountry/{id}")
    public String editCountry(@PathVariable("id") Long countryId, Model model) {
        // Retrieve the country information by ID from the service
        Country country = countryService.getCountryById(countryId);

        // Add the country object to the model to be passed to the view
        model.addAttribute("country", country);

        // Return the view name for the edit country page
        return "/Country/edit-country";
    }
    @GetMapping("/updateCountry")
    public String updateCountry(@ModelAttribute("country") Country country, Model model) {
        // Call the service to update the country in the database
        countryService.updateCountry(country);

        model.addAttribute("message", "Country updated successfully!"); // Add success message to model
        return "/Country/edit-country"; // Return to a success page
    }

    /** END OF COUNTRY FUNCTIONS **/

    /** START OF OPERATOR FUNCTIONS **/
    @RequestMapping("/addOperator")
    public String addOperatorForm() {
        return "/Operator/add-operator"; // Return the name of the JSP form file
    }

    @GetMapping("/saveOperator")
    public String saveOperator(Operator operator,Model model,BindingResult bindingResult) {

        if (bindingResult.hasErrors()) {
            model.addAttribute("message", " Failed to add Country!");
            return "/Operator/add-operator"; // Return back to the form if validation fails
        }
        operatorService.saveOperator(operator); // Call the service to save the Operator object

        model.addAttribute("message", "Operator added successfully!"); // Add success message to model
        return "Operator/add-operator"; // Redirect to the addOperator form after saving
    }

    @GetMapping("/manage-operator")
    public String manageOperator(Model model)
    {
        List<Operator> operatorList = operatorService.findOperators();
        model.addAttribute("operators", operatorList);
        return "/Operator/manage-operator";
    }


    /** END OF OPERATOR FUNCTIONS **/

    /**START OF TOUR FUNCTIONS**/
    @RequestMapping("/showaddform")

    public String showTourForm() {
        return "/Tour/add-tour";
    }

    @GetMapping("/addTour")
    public String addTour(Tour tour,BindingResult bindingResult,Model model) {
        tourService.saveTour(tour);
        if (bindingResult.hasErrors()) {
            model.addAttribute("message", " Failed to add Tour!");
            return "/Tour/add-tour"; // Return back to the form if validation fails
        }
        tourService.saveTour(tour); // Call the service to save the Tour object

        model.addAttribute("message", "Tour added successfully!"); // Add success message to model
        return "/Tour/add-tour";
    }
    @GetMapping("/deleteTour")
    public String RemoveTour(@RequestParam("tour_id")int tour_id,Model model)
    {
        List<Tour> tourList = tourService.findTour();
        for (int i = 0; i < tourList.size(); i++) {
            System.out.println(tourList.get(i).getCountries());
            if(tour_id==tourList.get(i).getId()){
                tourService.Delete(tourList.get(i));
            }
        }

        return editTourDetail(model);
    }


    @GetMapping("/manage-tour")
    public String editTourDetail(Model model)
    {
        List<Tour> tours = tourService.findTour();
        model.addAttribute("tours", tours);
        return "/Tour/manage-tour";
    }
    /** END OF TOUR FUNCTIONS **/




    /** START OF REVIEW FUNCTIONS **/
    @GetMapping("/reviews")
    public String displayReviews(Model model) {
        List<Review> reviews = reviewService.getAllReviews();
        model.addAttribute("reviews", reviews);
        return "reviews";
    }
    /** END OF REVIEW FUNCTIONS **/
}

