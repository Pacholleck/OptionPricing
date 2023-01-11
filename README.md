# Applied Finance: European Up-and-In Put Option
By Dustin Pacholleck <br/>
M.A Data Science and Business Analytics Student <br/>
University of Warsaw

## Usage of this Repository

There are two approaches for using the option pricer. 

1. Download the `OptionPricing_Pacholleck.Rmd` file and uncomment `devtools::install_github` in line 84. Don't forget to provide your git access token as well. This will install the `rccp` package directly from this Repo.
2. Clone the Repo, open the `OptionPricing_Pacholleck.Rmd` file, and uncomment `install.packages` in line 77. Make sure your file path is correct. This will use the ziped package provided in the files. 

## Objective

This project aims to use Monte Carlo Simulation for pricing a European style up-and-in put option with a barrier active between the moment of pricing and the option expiry.

Specifically, the project tries to:

1. find the theoretical price of the given option,
2. show the relation between the theoretical price of the given option and two factors (simultaneously):
    a) volatility of the underlying instrument returns, and
    b) time to maturity of the option.

It tries to achieve so, by building a `rccp` package. 

## Assumptions

The project assumes: 

* 10,000 Monte Carlo simulations,
* 252 number of time steps per year, and
* defining the barrier after inspection of its effect.


## Description of the Option

The given option is described as followed: 

* price of the underlying at the moment of option pricing: $S0 = 95$,
* strike price $K = 100$,
* annualized volatility rate $\sigma = 0.24$ 
* annualized risk-free rate $r = 0.07$
* time to maturity $t = 0.75$
  
A holder of an European option can exercise only at exercise date. The option includes an Up-and-In barrier which means the underlying price has to be higher than the barrier to activate the option.

In finance, an **option** is an agreement, which gives the holder a right for **buy** or **sell** a certain underlying instrument for a given price (*exercise price*) at a given moment in futures (*expiry date*).
**PUT** option -- gives the holder right to **sell** a given amount of underlying instrument for a given price at the given moment in future. 
`(Source: Lecture Slides)`
 
