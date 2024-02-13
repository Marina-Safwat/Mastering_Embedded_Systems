/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Pressure_Monitoring_System_Project
// File          : BIT_MATH.h
// Date          : Dec 29, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(ADDRESS,BIT)   ADDRESS |=  (1<<BIT)
#define RESET_BIT(ADDRESS,BIT) ADDRESS &= ~(1<<BIT)
#define TOGGLE_BIT(ADDRESS,BIT)  ADDRESS ^=  (1<<BIT)
#define READ_BIT(ADDRESS,BIT) ((ADDRESS) &   (1<<(BIT)))

#endif /* BIT_MATH_H_ */
