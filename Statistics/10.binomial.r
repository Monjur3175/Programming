 # Binomial MLE
 n_binom <- 20
 p_true <- 0.6
 data_binom <- rbinom(100, size = n_binom, prob = p_true)
 p_mle <- mean(data_binom) / n_binom
 # Poisson MLE
 lambda_true <- 3
 data_pois <- rpois(100, lambda = lambda_true)
 lambda_mle <- mean(data_pois)
 # Normal MLE
 mu_true <- 5
 sigma_true <- 2
 data_norm <- rnorm(100, mean = mu_true, sd = sigma_true)
 mu_mle <- mean(data_norm)
 sigma_mle <- sqrt(mean((data_norm - mu_mle)^2))
 # Output
 print(paste("Binomial MLE for p:", p_mle))
 print(paste("Poisson MLE for lambda:", lambda_mle))
 print(paste("Normal MLE for mu:", mu_mle))
 print(paste("Normal MLE for sigma:", sigma_mle))