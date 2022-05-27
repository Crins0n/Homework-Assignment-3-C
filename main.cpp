/* 
Christopher Hinson, 26MAY2022, COP2000 (Online)

Write a program that creates storefront for Gunter's Mountain Shop allowing the user to select whether they want to shop either the Outlet Store or Main Store. Determine the number of items the user would like to purchase and display the applicable tax, grand total (less tax), and grand total (including tax). Additionally, determine whether the user is a student. If the user is a student apply and display updated totals reflecting the student discount. */

#include <iomanip>
#include <iostream>

int main() {
  // Wholesale prices for Outlet Store
  const double WS_Boots = 59.99, WS_Fleece_Pullovers = 10.50,
               WS_Snow_Gaiters = 12.25, WS_Traction_Cleats = 14.99,
               WS_Sleeping_Bag = 30.00;

  // Wholesale prices for Main Facility
  const double WS_Stove = 129.99, WS_Wipes = 11.50, WS_Mag_Lite = 5.99,
               WS_Aid_Kit = 14.99, WS_After_Bite = 3.99;

  // Constant double representing sales tax
  const double sales_tax = 0.07;

  // Constant double representing student discount
  const double student_discount = 0.10;

  // Input for number of items purchased at the Outlet Store
  int number_boots, number_pullovers, number_gaiters, number_cleats,
      number_sleeping_bags;

  // Input for number of items purchased at the Main Store
  int number_stoves, number_wipes, number_mag_lites, number_aid_kits,
      number_after_bite;

  // Input to determining if the user is a student
  int student;

  double total_wholesale_order_outlet, total_wholesale_order_main,
      total_tax_outlet, total_tax_main, grand_total, gt_w_student_discount;

  std::cout << R"(             
    *****************************************
    **          //\                        **
    **         //  \  //\                  **
    **        //    \//  \       //\       **
    **       //            \    //  \      **
    **      //              \  //    \     **
    **     //                \//      \    **
    **    //                           \   **
    *****************************************
    ** Welcome to Gunter's Mountain Shop   **
    *****************************************
    
)";

  int menu;

  std::cout << "1. Shop the Outlet Store in Kenosha" << std::endl;
  std::cout << "2. Shop the Main Store in Waukesha" << std::endl;
  std::cout << "3. Quit" << std::endl;
  std::cout << std::endl;
  std::cout << "Enter a menu item (1-3): " << std::endl;
  std::cin >> menu;
  std::cout << std::endl;

  switch (menu) {
  case 1:
    std::cout << "How many Hunter Climbing Boots would you like to purchase?"
              << std::endl;
    std::cin >> number_boots;

    if (number_boots < 0) {
      number_boots = 0;
      if (number_boots == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << "How many Fleece Pullovers would you like to purchase?"
              << std::endl;
    std::cin >> number_pullovers;

    if (number_pullovers < 0) {
      number_pullovers = 0;
      if (number_pullovers == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << "How many Snow Gaiters would you like to purchase?"
              << std::endl;
    std::cin >> number_gaiters;

    if (number_gaiters < 0) {
      number_gaiters = 0;
      if (number_gaiters == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << "How many Traction Cleats would you like to purchase?"
              << std::endl;
    std::cin >> number_cleats;

    if (number_cleats < 0) {
      number_cleats = 0;
      if (number_cleats == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << "How many Sleeping Bags would you like to purchase?"
              << std::endl;
    std::cin >> number_sleeping_bags;

    if (number_sleeping_bags < 0) {
      number_sleeping_bags = 0;
      if (number_sleeping_bags == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }
    std::cout << std::setw(61) << std::setfill('*') << "*"
              << std::endl; // End of user purchase order
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2) << std::setfill(' ');
    std::cout << std::left << "Gunters Outlet Items" << std::right
              << std::setw(32) << "Sale Price" << std::endl;

    /* Table showing the wholesale price of items and the total wholesale price
    per item as inputted by the user at Gunters Outlet Store */

    std::cout << std::left << std::setw(21) << "Hunter Climbing Boots"
              << "\t" << std::setw(18) << "$59.99"
              << "Total = $" << std::setw(10) << WS_Boots * number_boots
              << "\n";

    std::cout << std::left << std::setw(21) << "Fleece Pullovers"
              << "\t" << std::setw(18) << "$10.50"
              << "Total = $" << std::setw(10)
              << WS_Fleece_Pullovers * number_pullovers << "\n";

    std::cout << std::left << std::setw(21) << "Snow Gaiters"
              << "\t" << std::setw(18) << "$12.25"
              << "Total = $" << std::setw(10)
              << WS_Snow_Gaiters * number_gaiters << "\n";

    std::cout << std::left << std::setw(21) << "Traction Cleats"
              << "\t" << std::setw(18) << "$14.99"
              << "Total = $" << std::setw(10)
              << WS_Traction_Cleats * number_cleats << "\n";

    std::cout << std::left << std::setw(21) << "Sleeping Bags"
              << "\t" << std::setw(18) << "$30.00"
              << "Total = $" << std::setw(10)
              << WS_Sleeping_Bag * number_sleeping_bags << "\n";

    std::cout << std::setfill('*') << std::setw(61) << "*"
              << "\n";
    std::cout << "\n";

    // Formula for calculating the total tax of inputted items at Outlet Store

    total_tax_outlet = sales_tax * ((WS_Boots * number_boots) +
                                    (WS_Fleece_Pullovers * number_pullovers) +
                                    (WS_Snow_Gaiters * number_gaiters) +
                                    (WS_Traction_Cleats * number_cleats) +
                                    (WS_Sleeping_Bag * number_sleeping_bags));

    // Formula for calculating the total wholesale order price of inputted items
    // at the Outlet Store

    total_wholesale_order_outlet = (WS_Boots * number_boots) +
                                   (WS_Fleece_Pullovers * number_pullovers) +
                                   (WS_Snow_Gaiters * number_gaiters) +
                                   (WS_Traction_Cleats * number_cleats) +
                                   (WS_Sleeping_Bag * number_sleeping_bags);

    // Grand total representing the total wholesale order plus tax of items
    // purchased

    grand_total = total_tax_outlet + total_wholesale_order_outlet;

    // Formula to determine the "Grand Total w/ Student Discount"

    gt_w_student_discount = grand_total - (grand_total * student_discount);

    // Shows the total tax, total wholesale order, and the grand total w/ tax

    std::cout << std::setfill(' ') << "Tax: $" << total_tax_outlet
              << std::setw(5) << "\t"
              << "Total: $" << total_wholesale_order_outlet << std::setw(5)
              << "\t"
              << "Total w/ Tax: $" << grand_total << std::endl;

    // Asking the user if they are a student

    std::cout << "Are you a student? Enter 1 - Yes or 2 - No "
              << "> ";
    std::cin >> student;

    // "If" statement determining elgibility of student discount and apply
    // formula
    if (student == 1) {
      std::cout << "You are elgible for our student discount!!" << std::endl;
      std::cout << "Discount: $" << student_discount * grand_total
                << std::setw(5) << "\t"
                << "Total: " << grand_total << std::setw(5) << "\t"
                << "Total w/ Disc: $" << gt_w_student_discount << std::endl;
    }
    else {
      std::cout << "Thank you for shopping." << std::endl;
    }
    break;

  case 2:
    std::cout << "How many Camp Stoves would you like to purchase?"
              << std::endl;
    std::cin >> number_stoves;

    if (number_stoves < 0) {
      number_stoves = 0;
      if (number_stoves == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }
    std::cout << "How many Bug Spray Wipes would you like to purchase?"
              << std::endl;
    std::cin >> number_wipes;

    if (number_wipes < 0) {
      number_wipes = 0;
      if (number_wipes == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << "How many Mag-Lites would you like to purchase?" << std::endl;
    std::cin >> number_mag_lites;

    if (number_mag_lites < 0) {
      number_mag_lites = 0;
      if (number_mag_lites == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << "How many First Aid Kits would you like to purchase?"
              << std::endl;
    std::cin >> number_aid_kits;

    if (number_aid_kits < 0) {
      number_aid_kits = 0;
      if (number_aid_kits == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << "How many After Bites would you like to purchase?"
              << std::endl;
    std::cin >> number_after_bite;
    if (number_after_bite < 0) {
      number_after_bite = 0;
      if (number_after_bite == 0) {
        std::cout << "Invalid entry... Value set to zero." << std::endl;
      }
    }

    std::cout << std::setw(61) << std::setfill('*') << "*"
              << std::endl; // End of user purchase order
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(2) << std::setfill(' ');
    std::cout << std::left << "Gunter's Main Store" << std::right
              << std::setw(32) << "Sale Price" << std::endl;

    /* Table showing the wholesale price of items and the total wholesale price
   per item as inputted by the user at Gunters Main Store */

    std::cout << std::left << std::setw(21) << "Camp Stoves"
              << "\t" << std::setw(18) << "$129.99"
              << "Total = $" << std::setw(10) << WS_Stove * number_stoves
              << "\n";

    std::cout << std::left << std::setw(21) << "Bug Spray Wipes"
              << "\t" << std::setw(18) << "$11.50"
              << "Total = $" << std::setw(10) << WS_Wipes * number_wipes
              << "\n";

    std::cout << std::left << std::setw(21) << "Mag-Lites"
              << "\t" << std::setw(18) << "$5.99"
              << "Total = $" << std::setw(10) << WS_Mag_Lite * number_mag_lites
              << "\n";

    std::cout << std::left << std::setw(21) << "First Aid Kits"
              << "\t" << std::setw(18) << "$14.99"
              << "Total = $" << std::setw(10) << WS_Aid_Kit * number_aid_kits
              << "\n";

    std::cout << std::left << std::setw(21) << "After Bite"
              << "\t" << std::setw(18) << "$3.99"
              << "Total = $" << std::setw(10)
              << WS_After_Bite * number_after_bite << "\n";

    std::cout << std::setfill('*') << std::setw(61) << "*"
              << "\n";
    std::cout << "\n";

    // Formula for calculating the total tax of inputted items at Gunter's Main
    // Store

    total_tax_main =
        sales_tax *
        ((WS_Stove * number_stoves) + (WS_Wipes * number_wipes) +
         (WS_Mag_Lite * number_mag_lites) + (WS_Aid_Kit * number_aid_kits) +
         (WS_After_Bite * number_after_bite));

    // Formula for calculating the total wholesale order price of inputted items
    // at the Main Store

    total_wholesale_order_main =
        (WS_Stove * number_stoves) + (WS_Wipes * number_wipes) +
        (WS_Mag_Lite * number_mag_lites) + (WS_Aid_Kit * number_aid_kits) +
        (WS_After_Bite * number_after_bite);

    // Grand total representing the total wholesale order plus tax of items
    // purchased

    grand_total = total_tax_main + total_wholesale_order_main;

    // Formula to determine the "Grand Total w/ Student Discount"

    gt_w_student_discount = grand_total - (grand_total * student_discount);

    // Shows the total tax, total wholesale order, and the grand total w/ tax

    std::cout << std::setfill(' ') << "Tax: $" << total_tax_main << std::setw(5)
              << "\t"
              << "Total: $" << total_wholesale_order_main << std::setw(5)
              << "\t"
              << "Total w/ Tax: $" << grand_total << std::endl;

    // Asking the user if they are a student

    std::cout << "Are you a student? Enter 1 - Yes or 2 - No "
              << "> ";
    std::cin >> student;

    // "If" statement determining elgibility of student discount and apply
    // formula
    if (student == 1) {
      std::cout << "You are elgible for our student discount!!" << std::endl;
      std::cout << "Discount: $" << student_discount * grand_total
                << std::setw(5) << "\t"
                << "Total: " << grand_total << std::setw(5) << "\t"
                << "Total w/ Disc: $" << gt_w_student_discount << std::endl;
    }
    else {
      std::cout << "Thank you for shopping." << std::endl;
    }
    break;

  case 3:
    std::cout << "You have exited the program." << std::endl;
    break; 

  default:
    if (menu < 1 || menu > 3)
      std::cout << "Error. You have entered an invalid option."
                << std::endl; 
  }
}
