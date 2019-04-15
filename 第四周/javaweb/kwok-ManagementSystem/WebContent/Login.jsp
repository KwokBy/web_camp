<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<%
String path=request.getContextPath(); 
String basePath= request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/"; 
%>
<!DOCTYPE HTML>
<html>
	<head>
	<base href="<%=basePath %>">
	<meta charset="utf-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>Home</title>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<meta name="description" content="" />
	<meta name="keywords" content="" />
	<meta name="author" content="" />
  	<!-- Facebook and Twitter integration -->
	<meta property="og:title" content=""/>
	<meta property="og:image" content=""/>
	<meta property="og:url" content=""/>
	<meta property="og:site_name" content=""/>
	<meta property="og:description" content=""/>
	<meta name="twitter:title" content="" />
	<meta name="twitter:image" content="" />
	<meta name="twitter:url" content="" />
	<meta name="twitter:card" content="" />

	<link href="https://fonts.googleapis.com/css?family=Roboto:300,400,700" rel="stylesheet">
	
	<!-- Animate.css -->
	<link rel="stylesheet" href="css/animate.css">
	<!-- Icomoon Icon Fonts-->
	<link rel="stylesheet" href="css/icomoon.css">
	<!-- Themify Icons-->
	<link rel="stylesheet" href="css/themify-icons.css">
	<!-- Bootstrap  -->
	<link rel="stylesheet" href="css/bootstrap.css">

	<!-- Magnific Popup -->
	<link rel="stylesheet" href="css/magnific-popup.css">

	<!-- Owl Carousel  -->
	<link rel="stylesheet" href="css/owl.carousel.min.css">
	<link rel="stylesheet" href="css/owl.theme.default.min.css">

	<!-- Theme style  -->
	<link rel="stylesheet" href="css/style.css">

	<!-- Modernizr JS -->
	<script src="js/modernizr-2.6.2.min.js"></script>
	<!-- FOR IE9 below -->
	<!--[if lt IE 9]>
	<script src="js/respond.min.js"></script>
	<![endif]-->

	</head>
	<body>
		
	<div class="gtco-loader"></div>
	
	<header id="gtco-header" class="gtco-cover" role="banner" style="background-image: url(images/img_4.jpg)">
		<div class="overlay"></div>
		<div class="gtco-container">
			<div class="row">
				<div class="col-md-12 col-md-offset-0 text-left">
					

					<div class="row row-mt-15em">
						<div class="col-md-7 mt-text animate-box" data-animate-effect="fadeInUp">
							<span class="intro-text-small">Welcome to my ManagenentSystem</span>
							<h1>信息管理系统</h1>	
						</div>
						<div class="col-md-4 col-md-push-1 animate-box" data-animate-effect="fadeInRight">
							<div class="form-wrap">
								<div class="tab">
									<ul class="tab-menu">
										<li class="gtco-second"><a href="#" data-tab="登录">登录</a></li>
										<li class="active gtco-first"><a href="#" data-tab="注册">注册</a></li>	
									</ul>
									<div class="tab-content">
										<div class="tab-content-inner active" data-content="登录">
<!-- 搞路径 -->	       				        <form action="UserServlet" methed="post"> 
                                              <input type="hidden" name="oper" value="login">                           
												<div class="row form-group">
													<div class="col-md-12">
													<%
													   //提示语显示登录判断
													   Object obj=request.getAttribute("flag");
													   if("false".equals(obj)){
													%>
													<li><span style="color:red">用户名或密码错误</span><li>
													<%} %>
													<%
													   //提示语显示修改密码判断
													   Object obj1=request.getAttribute("flag1");
													   if("true".equals(obj1)){
													%>
													<li><span style="color:red">密码修改成功</span><li>
													<%} %>
													<%
													   //提示语显示注册判断
													   Object obj3=request.getAttribute("flag2");
													   if("true".equals(obj3)){
													%>
													<li><span style="color:red">注册成功</span><li>
													<%}%>
														<label for="uname">用户名</label>
														<input type="text" class="form-control" name="uname" id="uname">
													</div>
												</div>
												<div class="row form-group">
													<div class="col-md-12">
														<label for="pwd">密码</label>
														<input type="password" class="form-control" name="pwd" id="pwd">
													</div>
												</div>

												<div class="row form-group">
													<div class="col-md-12">
														<input type="submit" class="btn btn-primary" value="登录">
													</div>
												</div>
											</form>	
										</div>
										<div class="tab-content-inner" data-content="注册">
<!-- 搞路径 -->								<form action="UserServlet"，methed="post">
 												<input type="hidden" name="oper" value="regiter">
												<div class="row form-group">
									
													<div class="col-md-12">
														<label for="uname">用户名</label>
														<input type="text" class="form-control" name="uname" id="uname" >
													</div>
												</div>
												<div class="row form-group">
													<div class="col-md-12">
														<label for="pwd">密码</label>
														<input type="password" class="form-control" name="pwd" id="pwd">
													</div>
												</div>
												<div class="row form-group">
													<div class="col-md-12">
														<label for="pwd2">再次确认密码</label>
														<input type="password" class="form-control" name="pwd2" id="pwd2">
													</div>
												</div>
												<div class="row form-group">
													<div class="col-md-12">
														<label for="sex">性别</label>
														<input type="text" class="form-control" name="sex" id="sex">
													</div>
												</div>
												
												<div class="row form-group">
													<div class="col-md-12">
														<input type="submit" class="btn btn-primary" value="注册">
													</div>
												</div>
											</form>	
										</div>

									

									</div>
								</div>
							</div>
						</div>
					</div>
							
					
				</div>
			</div>
		</div>
	</header>

	<div class="gototop js-top">
		<a href="#" class="js-gotop"><i class="icon-arrow-up"></i></a>
	</div>
	
	<!-- jQuery -->
	<script src="js/jquery.min.js"></script>
	<!-- jQuery Easing -->
	<script src="js/jquery.easing.1.3.js"></script>
	<!-- Bootstrap -->
	<script src="js/bootstrap.min.js"></script>
	<!-- Waypoints -->
	<script src="js/jquery.waypoints.min.js"></script>
	<!-- Carousel -->
	<script src="js/owl.carousel.min.js"></script>
	<!-- countTo -->
	<script src="js/jquery.countTo.js"></script>
	<!-- Magnific Popup -->
	<script src="js/jquery.magnific-popup.min.js"></script>
	<script src="js/magnific-popup-options.js"></script>
	<!-- Main -->
	<script src="js/main.js"></script>

	</body>
</html>
