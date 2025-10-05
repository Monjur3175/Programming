 # Parameters
 mu0 <- 5  # Null hypothesis mean
 mu1 <- 6  # True population mean
 sigma <- 2  # Population standard deviation
 n <- 30  # Sample size
 alpha <- 0.05  # Significance level
 # Generate sample data
 set.seed(123)
 sample_data <- rnorm(n, mean = mu1, sd = sigma)
 # Perform t-test
 t_test_result <- t.test(sample_data, mu = mu0, alternative = "greater")
 # Decision
 if (t_test_result$p.value < alpha) {
 decision <- "Reject H0"
 } else {
 decision <- "Fail to reject H0"
 }
# Output
 print(paste("Test Statistic:", t_test_result$statistic))
 print(paste("P-value:", t_test_result$p.value))
 print(paste("Decision:", decision))
 # Graphical Output
 par(mfrow = c(1, 2))
 # Histogram with critical region
 hist(sample_data, breaks = 30, col = "lightblue", main = "Sample Data", xlab = "Value", border = "white")
 abline(v = mu0, col = "red", lwd = 2)
 abline(v = mean(sample_data), col = "blue", lwd = 2)
 # Density plot with critical region
 plot(density(sample_data), col = "blue", lwd = 2, main = "Density Plot", xlab = "Value")
 abline(v = qt(1 - alpha, df = n-1), col = "red", lty = 2)