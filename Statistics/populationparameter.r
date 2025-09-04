 # Parameters
 mu <- 5
 sigma <- 2
 n <- 30
 N_sim <- 1000
 # Generate sample data
 set.seed(123)
 sample_data <- rnorm(n, mean = mu, sd = sigma)
 # Point estimates
 sample_mean <- mean(sample_data)
 sample_var <- var(sample_data)
 # Confidence intervals
 conf_int_mean <- t.test(sample_data)$conf.int
 conf_int_var <- c((n-1)*sample_var / qchisq(0.975, df = n-1),
                  (n-1)*sample_var / qchisq(0.025, df = n-1))
 # Output
 print(paste("Sample Mean:", sample_mean))
 print(paste("Sample Variance:", sample_var))
 print(paste("95% CI for Mean:", conf_int_mean))
 print(paste("95% CI for Variance:", conf_int_var))
 # Graphical Output
 par(mfrow = c(1, 2))
 # Histogram with mean and CI
 hist(sample_data, breaks = 30, col = "lightblue", main = "Sample Data with Mean", xlab = "Value", border = "white")
 abline(v = sample_mean, col = "red", lwd = 2)
 abline(v = conf_int_mean, col = "blue", lty = 2)
 # Boxplot
boxplot(sample_data, col = "lightgreen", main = "Boxplot of Sample Data", ylab = "Value")