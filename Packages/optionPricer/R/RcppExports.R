# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

getEuropeanPutPrice <- function(nInt, Strike, Spot, Vol, Rfr, Expiry, B, nReps = 1000L) {
    .Call(`_optionPricer_getEuropeanPutPrice`, nInt, Strike, Spot, Vol, Rfr, Expiry, B, nReps)
}

