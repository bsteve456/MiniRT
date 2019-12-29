int		inter_sphere(t_sphere sphere, t_ray ray)
{
	float a;
	float b;
	float c;
	float discr;
	vect vectOS;

	vectOS = vectSub(ray.orig, sphere.center);
	a = vectDot(ray.dir, ray.dir);
	b = 2 * vectDot(ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere.radius * sphere.radius);
	discr = (b * b) - (4 * a * c);
	if(discr >= 0.0000)
		return(1);
	return (0);
}

